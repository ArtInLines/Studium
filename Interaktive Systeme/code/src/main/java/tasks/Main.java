package tasks;

public class Main {
	public static void main(String[] args) {
		if (args.length > 0) switch (args[0]) {
			case "1":
				IS01_Colors.launch(args);
				return;

			case "2":
				IS02_TiefesGUI.launch(args);
				return;

			default:
				System.err.println("Unknown class to launch.");
				return;
		}
		System.err.println("You need to supply a command line argument to launch a task");
	}
}
