import javax.swing.*;
import java.awt.*;
import java.util.Random;
import java.util.Scanner;

public class Helix {
//extra credit included !!! i skipped hitting GM in overwatch to be here
     public static void main(String[] args) {
        System.out.println("UTSA - Fall 2023 - CS1083 - Section 003 - Prj 3 - Helix - written by: ");

        // 400x400 panel
        DrawingPanel panel = new DrawingPanel(400, 400);
        // Get Graphics object for drawing
        Graphics g = panel.getGraphics();

        // Set panel background to black
        panel.setBackground(Color.BLACK);

        // Start helix drawing process nerd
        drawHelix(panel);
    }
//this is getColor method it is used to get the color
     public static Color getColor(int colorCode) {
        // Return color based on code
        switch (colorCode) {
            case 0: return Color.RED;
            case 1: return Color.ORANGE;
            case 2: return Color.YELLOW;
            case 3: return Color.GREEN;
            case 4: return Color.BLUE;
            case 5: return Color.PINK;
            case 6: return Color.GRAY;
            case 7: return Color.DARK_GRAY;
            case 8: return Color.BLACK;
            default: return Color.WHITE;
        }
    }
//this is newPos method it is used to move the line
    public static int newPos(boolean clockwise, int lastMovement, int[] lineCoordinates) {
        final int STEP = 10;
        final int MIN_X = 100, MAX_X = 300, MIN_Y = 100, MAX_Y = 300;

        // weird updating stufff
        switch (lastMovement) {
            case 0: // Right
                if (lineCoordinates[0] + STEP <= MAX_X) {
                    lineCoordinates[0] += STEP;
                    lineCoordinates[2] -= STEP;
                } else {
                    lineCoordinates[1] += STEP;
                    lineCoordinates[3] -= STEP;
                    lastMovement = 1;
                }
                  break;
            case 1: // Down
                  if (lineCoordinates[1] + STEP <= MAX_Y) {
                    lineCoordinates[1] += STEP;
                    lineCoordinates[3] -= STEP;
                } else {
                    lineCoordinates[0] -= STEP;
                    lineCoordinates[2] += STEP;
                    lastMovement = 2;
                }
                 break;
            case 2: // Left
                if (lineCoordinates[0] - STEP >= MIN_X) {
                    lineCoordinates[0] -= STEP;
                    lineCoordinates[2] += STEP;
                } else {
                    lineCoordinates[1] -= STEP;
                    lineCoordinates[3] += STEP;
                    lastMovement = 3;
                  }
                break;
            case 3: // Up
                if (lineCoordinates[1] - STEP >= MIN_Y) {
                    lineCoordinates[1] -= STEP;
                    lineCoordinates[3] += STEP;
                } else {
                    lineCoordinates[0] += STEP;
                    lineCoordinates[2] -= STEP;
                    lastMovement = 0;}
                break;
        }
        return lastMovement;
    }
    //this is drawHelix method it is used to draw the helix
    public static void drawHelix(DrawingPanel panel) {
        int numMovements;
        int speed;
        int speed_inp;

        String text = "UTSA - CS1083 - Section 003 - Prj 3 - Helix - ";
        Graphics g = panel.getGraphics();
        g.setColor(Color.WHITE);
        Font font = new Font("Arial", Font.PLAIN, 13);
        g.setFont(font);
        FontMetrics fm = g.getFontMetrics(font);
        int textWidth = fm.stringWidth(text);
        int x = (400 - textWidth) / 2; // Center text horizontally
        int y = 60; // text above square
        g.drawString(text, x, y);
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please, input the speed (1-10): ");
        speed_inp = scanner.nextInt();
        speed = 1000 / speed_inp; // Adjusting speed
        System.out.print("Please, input the number of times the line will be shown: ");
        numMovements = scanner.nextInt();

        int[] lineCoordinates = new int[]{100, 100, 300, 300};
        int lastMovement = 0;
        int[] colorCodes = {0, 1, 2, 3, 4, 5, 6, 7, 8};

        // draw
        for (int i = 0; i < numMovements; i++) {
            // Clear background, redraw
            g.setColor(Color.BLACK);
            g.fillRect(0, 0, 400, 400);
            g.setColor(Color.WHITE);
            g.setFont(font);
            g.drawString(text, x, y);
            g.fillRect(100, 100, 200, 200);
            g.drawString("Speed: " + speed_inp, 180, 85);
            g.drawString("i: " + (i + 1), 200, 320);
            g.drawString("(" + lineCoordinates[0] + ", " + lineCoordinates[1] + "), ", 130, 350);
            g.drawString("(" + lineCoordinates[2] + ", " + lineCoordinates[3] + ")", 195, 350);

            // rand color
            Random random = new Random();
            int randomColorCode = colorCodes[random.nextInt(colorCodes.length)];
            Color lineColor = getColor(randomColorCode);
            g.setColor(lineColor);
            int newMovement = newPos(true, lastMovement, lineCoordinates);
            lastMovement = newMovement;
            g.drawLine(lineCoordinates[0], lineCoordinates[1], lineCoordinates[2], lineCoordinates[3]);

            // CSpeed
            try {
                Thread.sleep(speed);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
