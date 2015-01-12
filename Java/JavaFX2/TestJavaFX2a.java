public class DemoFX extends Application {
    @Override
    public void start(Stage primaryStage) throws IOException {
        // version FX vs Swing
        // BorderPane pane = new BorderPane();
        // Label toppanetext = new Label("Appli Text");
        // pane.setTop(toppanetext);
        // Label centerpanetext = new Label ("Some data here");
        // pane.setCenter(centerpanetext);
        // version avec FXML
        Pane pane = (Pane)
        FXMLLoader.load(getClass().getResource("ParfileExplorer.fxml"));
        Scene sc = new Scene(pane, 300,500);
        sc.getStylesheets().add("test.css");
        primaryStage.setTitle("Appli Text");
        primaryStage.setScene(sc);
        primaryStage.show();
}
public static void main(String[] args) {
    launch(args);
}
