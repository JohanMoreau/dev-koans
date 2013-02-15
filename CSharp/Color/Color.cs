using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

class ColorExample : Form {
	public ColorExample() {
		Text = "Colors";
		Size = new Size(360, 120);
		Paint += new PaintEventHandler(OnPaint);
		CenterToScreen();
	}
	void OnPaint(object sender, PaintEventArgs e){      
		Graphics g = e.Graphics;
		g.FillRectangle(Brushes.Sienna, 10, 15, 90, 60);
		g.FillRectangle(Brushes.Green, 130, 15, 90, 60);
		g.FillRectangle(Brushes.Maroon, 250, 15, 90, 60);
		g.Dispose();
		
	}
	public static void Main() {
		Application.Run(new ColorExample());
	}
}