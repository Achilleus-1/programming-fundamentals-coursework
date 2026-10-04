import java.util.ArrayList;
import java.util.Scanner;

public class Cyclone {
  public static Scanner input = new Scanner(System.in);
    public static final int gMAX_CYCLONES = 50;
    public static int gDatabaseSize;
     public static ArrayList<Integer> gWindSpeed = new ArrayList<>();
    public static void main(String[] args) {
        System.out.println("Fall 2023 - UTSA - CS1083 - Section 003 - Project 2 - Cyclone - written by ");

        gDatabaseSize = getValidatedValue("How many cyclones are in the database? (Max 50): ", gMAX_CYCLONES);
        populateWindSpeeds();

        int choice;
        do {
            MainMenu();
            choice = getValidatedValue("Select an option: ", 5);
            handleMenuOption(choice);
        } while (choice != 0);

        input.close();
    }
     private static void MainMenu() {
        System.out.println("MAIN MENU");
        System.out.print("0 - Exit," + '\t');
        System.out.print("1 - Add/Update," + '\t');
        System.out.print("2 - Summary," + '\t');
        System.out.print("3 - Clear Database," + '\t');
        System.out.print("4 - Show Cyclones," + '\t');
        System.out.println("5 - Swap Cyclones");
    }
     
    private static void populateWindSpeeds() {
        for (int i = 0; i < gDatabaseSize; i++) {
            System.out.print("Enter wind speed for cyclone " + (i + 1) + ": ");
            gWindSpeed.add(input.nextInt());
        }
    }
  
    private static void handleMenuOption(int option) {
        if (option == 1) {
            addUpdCyclone();
        } else if (option == 2) {
            summary();
        } else if (option == 3) {
            clearDatabase();
        } else if (option == 4) {
            showCyclones();
        } else if (option == 5) {
            swapCyclones();
        } else if (option != 0) {
            System.out.println("Invalid option. Please try again.");
        }
    }
    private static void summary() {
        System.out.println("Cyclones' Classification Summary");
        String[] categories = {"Tropical Depression", "Tropical Storm", "Hurricane Category 1", "Hurricane Category 2", "Hurricane Category 3", "Hurricane Category 4", "Hurricane Category 5"};
        int[] minSpeeds = {0, 39, 74, 96, 111, 130, 157};
        int[] maxSpeeds = {38, 73, 95, 110, 129, 156, 1000};

        for (int i = 0; i < categories.length; i++) {
            int count = 0;
            for (Integer speed : gWindSpeed) {
                if (speed >= minSpeeds[i] && speed <= maxSpeeds[i]) {
                    count++;
                }
            }
            System.out.println(categories[i] + ": " + count);
        }
    }
    private static void clearDatabase() {
        for (int i = 0; i < gDatabaseSize; i++) {
            gWindSpeed.set(i, 0);
        }
    }
    private static void showCyclones() {
        System.out.println("SHOW CYCLONES");
        for (int i = 0; i < gDatabaseSize; i++) {
            System.out.println("Cyclone " + i + ": " + gWindSpeed.get(i) + " mph");
        }
    }
   private static void swapCyclones() {
    System.out.println("Swap cyclones");
    int firstIndex = getValidatedValue("Enter index of first cyclone (0 to " + (gDatabaseSize - 1) + "): ", gDatabaseSize - 1);
    
    int secondIndex = getSecondCycloneIndex(firstIndex);

    swapWindSpeeds(firstIndex, secondIndex);
}
 private static void addUpdCyclone() {
        System.out.println("ADD/UPDATE CYCLONE");
        int index = getValidatedValue("Enter the index (0 to " + (gDatabaseSize - 1) + "): ", gDatabaseSize - 1);
        System.out.println("Current wind speed: " + gWindSpeed.get(index));
        gWindSpeed.set(index, getValidatedValue("Enter new wind speed (0 - 1000): ", 1000));
    }
   
private static int getSecondCycloneIndex(int firstIndex) {
    int index;
    while (true) {
        index = getValidatedValue("Enter index of second cyclone (0 to " + (gDatabaseSize - 1) + "): ", gDatabaseSize - 1);
        if (index != firstIndex) {
            break;
        }
        System.out.println("Indices cannot be the same. Please try again.");
    }
    return index;
}

private static void swapWindSpeeds(int firstIndex, int secondIndex) {
    int temp = gWindSpeed.get(firstIndex);
    gWindSpeed.set(firstIndex, gWindSpeed.get(secondIndex));
    gWindSpeed.set(secondIndex, temp);
}
   private static int getValidatedValue(String message, int maxValue) {
    int value;

    while (true) {
        System.out.print(message);
        while (!input.hasNextInt()) {
            input.next(); // Clear the invalid input
            System.out.print("Invalid input. Please enter a number: ");
        }

        value = input.nextInt();

        if (value >= 0 && value <= maxValue) {
            return value;
        }

        System.out.println("Value out of range. Please try again.");
    }
   }
}
