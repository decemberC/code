import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.stage.Stage;
public class Jframefx extends Application{
  @Override
	public void start(Stage stage){
		Scene screen = new Scene(new FlowPane(),640,300);
		stage.setScene(screen);
		stage.show();
	}
	public static void main(String[] args){
		launch();
	}
}
