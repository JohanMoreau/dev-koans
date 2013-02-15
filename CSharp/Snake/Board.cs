using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Drawing.Design;

public class Board : UserControl {
	private const int width = 300, height = 300;
	private const int dotSize = 10, maxDot = 900;
	private const int randPos = 27, startPos = 50;
	private int[] x = new int[maxDot];
	private int[] y = new int[maxDot];
	private int dots = 3, apple_x, apple_y;
	private bool left = false, right = true;
	private bool up = false, down = false;
	private bool inGame = true;
	private Timer timer;
	private Bitmap dot, apple, head;
	public int borderWidth, titleBarHeight;
	public Board() {
		BackColor = Color.Black;
		DoubleBuffered = true;
		this.ClientSize = new Size(width, height);
		try {
			dot   = new Bitmap("dot.png");
			apple = new Bitmap("apple.png");
			head  = new Bitmap("head.png");
		} catch (Exception e) {
			Console.WriteLine(e.Message);
			Environment.Exit(1);
		}
		for (int z = 0; z < dots; z++) {
			x[z] = startPos - z * dotSize;
			y[z] = startPos;
		}
		locateApple();
		timer = new Timer();
		timer.Enabled = true;
		timer.Interval = 100;
		timer.Tick += new System.EventHandler(this.OnTick);
		Paint += new PaintEventHandler(this.OnPaint);
		KeyUp += new KeyEventHandler(OnKeyUp);
	}
	private void OnTick(object sender, EventArgs e) {
		if (inGame) {
			checkApple();
			checkCollision();
			move();
		}
		this.Refresh();
	}
	private void OnPaint(object sender, PaintEventArgs e) {	
		Graphics g = e.Graphics;
		if (inGame) {
			g.DrawImage(apple, apple_x, apple_y);
			for (int z = 0; z < dots; z++)
				g.DrawImage((z == 0) ? head : dot, x[z], y[z]);
		} else {
			gameOver(g);
		}
	}
	private void gameOver(Graphics g) {	
		String msg = "Game Over";
		StringFormat format = new StringFormat();
		format.Alignment = StringAlignment.Center;
		format.LineAlignment = StringAlignment.Center;
		g.DrawString(msg, Font, Brushes.White, ClientRectangle, format);
				timer.Stop();
	}
	private void checkApple() {	
		if ((x[0] == apple_x) && (y[0] == apple_y)) {
			dots++;
			locateApple();
		}
	}
	private void move() {	
		for (int z = dots; z > 0; z--) {
			x[z] = x[(z - 1)];
			y[z] = y[(z - 1)];
		}
		if (left)   x[0] -= dotSize;
		if (right)  x[0] += dotSize;
		if (up)     y[0] -= dotSize;
		if (down)   y[0] += dotSize;
	}	
	private void checkCollision() {	
		for (int z = dots; z > 0; z--)
			if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z]))
				inGame = false;
		if (y[0] > height - dotSize - titleBarHeight - borderWidth)
			inGame = false;
		if (y[0] < 0)
			inGame = false;
		if (x[0] > width - dotSize - 2 * borderWidth)
			inGame = false;
		if (x[0] < 0)
			inGame = false;
	}	
	private void locateApple() {
		Random rand = new Random();
		int r = (int)(rand.Next(randPos));
		apple_x = ((r * dotSize));
		r = (int)(rand.Next(randPos));
		apple_y = ((r * dotSize));
	}
	private void OnKeyUp(object sender, KeyEventArgs e) {	
		int key = (int) e.KeyCode;
		if ((key == (int) Keys.Left) && (!right)) {
			left = true; up = false; down = false;
		}
		if ((key == (int) Keys.Right) && (!left)) {
			right = true; up = false; down = false;
		}
		if ((key == (int) Keys.Up) && (!down)) {
			up = true; right = false; left = false;
		}
		if ((key == (int) Keys.Down) && (!up)) {
			down = true; right = false; left = false;
		}
	}
}

