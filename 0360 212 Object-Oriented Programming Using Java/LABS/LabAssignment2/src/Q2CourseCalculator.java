/**
 * PROJECT:     Lab 2 - Question 2
 * FILE:        Q2CourseCalculator.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: Student Grade Calculator. This program:
                (a) asks the student to input his/her name, student ID, marks for 5 courses,
                (b) calculates the average;
                (c) determines the letter grade of each course;
                (d) records the number of courses whose final letter grade is A+, A, A-, .... , F+, F, F-;
                (e) Outputs the following information: student name, student ID, listing of marks, the average;
                    letter grade for each course, and the number of courses in each letter grade category.
 */


import javax.swing.JOptionPane;   // user I/O
import java.util.StringTokenizer; // used to tokenize string for first and last name


public class Q2CourseCalculator {

    private final static int numberOfCourses = 5;
    private final static int idLength        = 9; // ensure id is nine digits (based on U Windsor id's)
    private final static String[] pos        = {"first", "second", "third", "fourth", "fifth"};

    public static void main(String args[]) {

        // Test data
        /**
         String name = "Jason Choquette";
         String id   = "104337378";
         float[] marks = new float[numberOfCourses];
         marks[0] = 85.5f;
         marks[1] = 72.3f;
         marks[2] = 65.7f;
         marks[3] = 95f;
         marks[4] = 12f;
         */

        // methods to obtain and validate student data
        String name   = getStudentName();
        String id     = getStudentId();
        float[] marks = getStudentMarks();

        // create a student and print the student info
        Q2Student student = new Q2Student(name, id, marks);
        student.printStudentInfo();
    }





    /******************************************************************************
     METHOD		    : getStudentName

     DESCRIPTION	: This method obtains and validates the student's name.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: returns the student's full name.
     ******************************************************************************/
    public static String getStudentName(){

        String studentName =  JOptionPane.showInputDialog("Please enter your full name (first and last): ");
        StringTokenizer st = new StringTokenizer(studentName, " "); // we want first and last name

        // make sure we have fist name and last name. i.e., two strings
        while(st.countTokens() != 2) {

            // ask again for full name
            JOptionPane.showMessageDialog(
                    null, "Please enter your first and last name separated by a space",
                    "Error", JOptionPane.ERROR_MESSAGE);
            studentName =  JOptionPane.showInputDialog("First and Last name: ");
            st = new StringTokenizer(studentName, " ");
        }

        return studentName;
    }




    /******************************************************************************
     METHOD		    : getStudentId

     DESCRIPTION	: This method obtains and validates the student's id.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: the student's id.
     ******************************************************************************/
    public static String getStudentId(){

        String id =  JOptionPane.showInputDialog("Please enter your student id (" + idLength +" digits): ");
        id = id.replaceAll("\\s", ""); // remove any whitespace

        while(id.length() != idLength) {

            JOptionPane.showMessageDialog(null, "Please enter a valid student id! ",
                    "Error", JOptionPane.ERROR_MESSAGE);
            id =  JOptionPane.showInputDialog("Please enter your student id (" + idLength +" digits): ");
            id.replaceAll("\\s", "");
        }

        return id;
    }




    /******************************************************************************
     METHOD		    : getStudentMarks

     DESCRIPTION	: This method obtains and validates the student's course marks.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: array of type float
                    : Description	: the student's five marks.
     ******************************************************************************/
    public static float[] getStudentMarks() {

        float[] marks =  new float[numberOfCourses]; // array to store student's marks

        for(int i = 0; i < numberOfCourses; i++) {

            // obtain mark from user
            marks[i] = Float.parseFloat(JOptionPane.showInputDialog("Please enter your " + pos[i] + " course mark: "));

            // until a valid mark is obtained...
            while(!isValidMark(marks[i])) {
                JOptionPane.showMessageDialog(null, "Please enter a valid mark. ",
                        "Error", JOptionPane.ERROR_MESSAGE);
                marks[i] = Float.parseFloat(JOptionPane.showInputDialog("Please enter your " + pos[i] +
                        " course mark: "));
            }
        }

        return marks;
    }




    /******************************************************************************
     METHOD		    : isValidMark

     DESCRIPTION	: This method validates a student's mark.

     INPUT			: Type			: float
                    : Description	: the student's mark to be validated.

     OUTPUT			: Type 			: boolean
                    : Description	: returns true if mark is valid, false otherwise.
     ******************************************************************************/
    private static boolean isValidMark(float mark)
    {
        if(mark >= 0 && mark <= 100) // valid marks range from 0 to 100
            return true;

        return false;
    }


} // end class Q2CourseCalculator
