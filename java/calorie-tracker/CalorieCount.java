import java.util.Scanner;

public class CalorieCount {
    public static void main(String[] args) {

        Scanner scnr = new Scanner(System.in);
        System.out.println("Fall 2023 - CS1083 - Section 003 - Project 1 - CaloriesCount - written by ");
        System.out.println("");
        int[] calorieCounts = new int[7];
        String[] daysOfWeek = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
//make list to organize and set days of week without having to make a big ugly blob of unorganized code
        for (int i = 0; i < 7; i++) {
            System.out.print("Calories burnt on " + daysOfWeek[i] + ": ");
            calorieCounts[i] = scnr.nextInt();
        }
        System.out.println("");
        System.out.println("Week"+"\t"+"Monday"+"\t"+"Tuesday"+"\t"+"Wednesday"+"\t"+"Thursday"+"\t"+"Friday"+"\t"+"Saturday"+"\t"+"Sunday"+"\t"+"Total");
//writes out all the labels for the chart
        //the indentaitons turn out very odd on the days of the week for no reason but it works and I am happy with the way it turned out
        int weeklyTotal = 0;
        int monthlyTotal = 0;

        int dayOfMonth = 1;
        int startingDay = 1;
        int weekOfMonth = 1;
//establishing all our variables needed
        for (int week = 1, day = 0; day < 30; week++) {
            System.out.print(weekOfMonth+"\t");

            for (int i = 0; i < 7; i++, day++) {
                if (day < 30) {
                    if (i < startingDay - 1) {
                        System.out.print("0-0"+"\t");
                    } else {
                        System.out.print(dayOfMonth + "-" + calorieCounts[i] + "\t");
                        weeklyTotal += calorieCounts[i];
                        monthlyTotal += calorieCounts[i];
                        dayOfMonth++;
                    }
                } else {
                    System.out.print("0-0"+"\t");
                }
            }
//establishing day of month system with the 0-0 andb stuff
            System.out.println("W" + weekOfMonth + "-" + weeklyTotal);
            weeklyTotal = 0;
            weekOfMonth++;
        }

        System.out.println("Total Calories: " + monthlyTotal);
//prints final count
    }
}