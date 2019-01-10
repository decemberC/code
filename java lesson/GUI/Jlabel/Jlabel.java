/*show how to use jlabel and setbounds.Need to remember setBounds can be effective only when setLayout(null)*/
import javax.swing.JLabel;
import javax.swing.JFrame;
public class Jlabel{
	public static void main(String[] args){
		JFrame sZframe = new JFrame("Jlabel.java");
		JFrame sBframe = new JFrame("JBlabel.java");
		JLabel label = new JLabel("Hellow World!!!");
		JLabel sBlabel = new JLabel("Hellow World!!!");
		sBframe.setLayout(null);
		label.setBounds(0,0,1,1);
		sBlabel.setBounds(50,50,100,24);
	    sZframe.setSize(1920,1080);
		sBframe.setBounds(0,0,1920,1080);
		sBframe.add(sBlabel);
		sZframe.add(label);
		sBframe.setVisible(true);
		sZframe.setVisible(true);
	}
}