import java.awt.*;
import java.util.Scanner;
public class ScreenSaver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the text for the screen saver:");
        String userInput = scanner.nextLine();

        DrawingPanel panel = new DrawingPanel(500, 500);
        Graphics g = panel.getGraphics();
        panel.setBackground(Color.BLACK);

        int red = 255, green = 255, blue = 255;
        int colorIndex = 0;
        int x = 500, y = 500;

        while (true) {
            panel.clear();

            g.setColor(new Color(red, green, blue));
            g.drawString(userInput + " " + red + ", " + green + ", " + blue, x, y);
            switch (colorIndex) {
                case 0:
                    red -= 5;
                    if (red <= 0) {
                        red = 255;
                    }
                    break;
                case 1:
                    green -= 5;
                    if (green <= 0) {
                        green = 255;
                    }
                    break;
                case 2:
                    blue -= 5;
                    if (blue <= 0) {
                        blue = 255;
                    }
                    break;
            }
            colorIndex = (colorIndex + 1) % 3;

            x -= 5;
            y -= 5;
            if (x < 0 || y < 0) {
                x = 500;
                y = 500;
            }

            panel.sleep(50);
        }
    }
}