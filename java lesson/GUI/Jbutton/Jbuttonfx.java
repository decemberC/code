import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.acene.control.Button;
import javafx.scene.layout.*;
import java.awt.*;

public class Jbuttonfx extends Application{
 @Override
  public void start(Stage primarystage){
    Dimension screensize = new Dimension();
    Button bu = new Button();
    Scene base = new Scene(FlowPane(bu),);
  }
  public static void main(String[] args){
   launch();
  }
}
