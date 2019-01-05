import javax.swing.JFrame;
public class Jframe{
	
	public static void main(String[] args){
	    JFrame screen = new JFrame();
		JFrame bigScreen = new JFrame();
		JFrame namedscreen = new JFrame("Hello world!!!");
		bigScreen.setBounds(0,0,1920,1080);
		screen.setVisible(true);
		bigScreen.setVisible(true);
		namedscreen.setVisible(true);
	}
}