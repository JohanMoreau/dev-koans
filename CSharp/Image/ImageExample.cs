using System;
using System.Drawing;
using System.Windows.Forms;

class ImageExample : Form {
	private Bitmap image;
	public ImageExample() {
		Text = "Image";
		loadImage();
		ClientSize = new Size(image.Width, image.Height);
		Paint += new PaintEventHandler(OnPaint);
		CenterToScreen();
	}
	void loadImage() {
		try {    
			image = new Bitmap("ipv6.png");
		} catch (Exception e) {
			Console.WriteLine(e.Message);
			Environment.Exit(1);
		}
	}
	void OnPaint(object sender, PaintEventArgs e){      
		Graphics g = e.Graphics;	
		Rectangle r = new Rectangle(1, 1, image.Width, image.Height);
		g.DrawImage(image, r);
	}
	public static void Main() {
		Application.Run(new ImageExample());
	}
}