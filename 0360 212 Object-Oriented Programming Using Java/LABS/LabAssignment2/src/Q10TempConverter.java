/**
 * PROJECT:     Lab 2 - Question 10
 * FILE:        Q10TempConverter.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Rewrote the whole program. I have ADD. Couldn't stand it. I'll take the zero on this one...
 */


import javax.swing.*; // user I/O


public class Q10TempConverter {

    public static void main(String[] args) {

        int    option;
        float  degree1;
        String degree;
        String input;

        while(true) { // run until user quits...

            input = JOptionPane.showInputDialog(
                    " 1. For " + Unit.FAHRENHEIT + " to " + Unit.CELSIUS + ".\n" +
                    " 2. For " + Unit.CELSIUS + " to " + Unit.FAHRENHEIT + ".\n" +
                    " 3. Quit."
            );

            option = Integer.parseInt(input);
            switch (option){

                case 1:
                    degree = JOptionPane.showInputDialog("Enter the temperature in " + Unit.FAHRENHEIT + ": ");
                    degree1 = convertToCelsius(Float.parseFloat(degree));
                    printResult(degree1, Unit.CELSIUS);
                    break;

                case 2:
                    degree = JOptionPane.showInputDialog("Enter the temperature in " + Unit.CELSIUS + ": ");
                    degree1 = convertToFahrenheit(Float.parseFloat(degree));
                    printResult(degree1, Unit.FAHRENHEIT);
                    break;

                case 3:
                    System.exit(0);

                default:
                    JOptionPane.showMessageDialog(null,"Not a valid option.",
                            "Invalid Option", JOptionPane.WARNING_MESSAGE);
                    break;
            }
        }
    } // end main

    static float convertToFahrenheit(float degree) { return (degree * 9 / 5.0f) + 32; } // need to divide by float or will return 0.0

    static float convertToCelsius(float degree) { return (degree - 32) * (5 / 9.0f); } // / need to divide by float or will return 0.0

    static void printResult(float temp, String units){

        String result = String.format("The temperature in " + units + " is %.01f  degrees.", temp);
        JOptionPane.showMessageDialog(null, result , "Result", JOptionPane.INFORMATION_MESSAGE);
    }

    // I don't like 'magic strings'...
    public static class Unit{
        final static String FAHRENHEIT = "FAHRENHEIT";
        final static String CELSIUS    = "CELSIUS";
    }
} // end class Q10Temperature
