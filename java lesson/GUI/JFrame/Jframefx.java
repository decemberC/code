import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.stage.Stage;
public class Jframefx extends Application{
  @Override
	public void start(Stage stage){
		Stage namedstage = new Stage();
		Scene screen = new Scene(new FlowPane(),640,300);
		Scene namedscene = new Scene(new FlowPane(),1920,1080);
		namedstage.setTitle("Hello world!");
		namedstage.setScene(namedscene);
		namedstage.setFullScreen(false);
		namedstage.show();
		stage.setScene(screen);
		stage.show();
	}
	public static void main(String[] args){
		launch();
	}
}
