import javax.swing.JFrame;
import javax.swing.JButton;
public class Jbutton{
	public static void main(String[] args){
		JFrame scene = new JFrame("Jbutton.java");
		scene.setLayout(null);
		scene.setBounds(0,0,720,480);
		JButton bu = new JButton("Hello world!");
		bu.setBounds(0,0,100,100);
		scene.add(bu);
		scene.setVisible(true);
	}
}