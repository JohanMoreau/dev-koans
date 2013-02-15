using System.Drawing;
using System.Windows.Forms;

class SimpleWindow : Form {	
	public SimpleWindow() {
		Label label = new Label();
		label.Text = "My first System.Windows.Forms application";
		label.Dock = DockStyle.Fill;
		
		this.Controls.Add(label);
		this.Text = "Hello";
		this.Size = new Size(250, 200);
		this.CenterToScreen();
	}
	public static void Main(string[] args) {
		Application.Run(new SimpleWindow());
	}
}