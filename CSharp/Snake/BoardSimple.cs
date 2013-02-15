using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Drawing.Design;

public class BoardSimple : UserControl {
	private const int width = 300,  height = 300;
	private const int dotSize = 10, maxDot = 900;
	private const int randPos = 27, startPos = 50;
	private int[] x = new int[maxDot];
	private int[] y = new int[maxDot];
	private int dots = 3;
	private Bitmap dot, apple, head;

	public BoardSimple() {
		BackColor = Color.Black;
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
		Paint += new PaintEventHandler(this.OnPaint);
	}

	private void OnPaint(object sender, PaintEventArgs e) {	
		Graphics g = e.Graphics;
		g.DrawImage(apple, 0 , 0);
		for (int z = 0; z < dots; z++)
			g.DrawImage((z == 0) ? head : dot, x[z], y[z]);
	}
}