import javafx.application.Application;
import javafx.scene.control.Label;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.*;
import java.awt.*;
public class Jlabelfx extends Application{
	@Override
	public void start(Stage primarystage){
	 Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
	  Label label=new Label("Hello World");
	 Scene basescene = new Scene(new FlowPane(label),screenSize.width,screenSize.height-100);
	 primarystage.setScene(basescene);
	 primarystage.show();
	 
	}
	public static void main(String[] args){
		launch();
	}
}