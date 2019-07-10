/**
 * PROJECT:     Lab 2 - Question 2
 * FILE:        Q2Student.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: This class represents a student object. Used in the Q2CourseCalculator class.
 *              It also contains methods to convert grades and print student info.
 *
 */


public class Q2Student {

    final private int numberOfCourses = 5;
    private String    name;
    private String    studentId;
    private float[]   marks;
    private String[]  letterGrades = new String[numberOfCourses];
    int[]             gradeCount = new int[14]; // used to keep track of the number of letter grades earned.
                                                // i.e., 2 A+'s, 1 B, 1 B-, 1 C+.

    /** please see below for description of this data structure */
    private String[]  grades = {"F-", "F ",
                                "D-", "D ", "D+",
                                "C-", "C ", "C+",
                                "B-", "B ", "B+",
                                "A-", "A ", "A+"};

    /** This array is used in the conversion of numeric grades to letter grades in the method convertNumericToLetter
     * (see definition below).
     * Example: Numeric grade: 94.3%:
     *
     * if(grade >= 93 && grade <= 100) { gradeCount[13] += 1; return grades[13]; }
     *
     * ... since 94.3 is in the range of 93 and 100, this is an A+ and found in grades[13] (above).
     * ... the gradeCount array is updated to reflect occurrence of this letter grade as well.
    */

    // I used the grade point as the index to convert numerical grades to letter grades...
    /*  Letter Grade          Range %       Grade Point
            A+              93 - 100            13
            A               86 - 92.9           12
            A-              80 - 85.9           11
            B+              77 - 79.9           10
            B               73 - 76.9           09
            B-              70 - 72.9           08
            C+              67 - 69.9           07
            C               63 - 66.9           06
            C-              60 - 62.9           05
            D+              57 - 59.9           04
            D               53 - 56.9           03
            D-              50 - 52.9           02
            F               35 - 49.9           01
            F-              0  - 34.9           00
     */
     // source: http://www1.uwindsor.ca/advisingcentre/marking-scale





    /******************************************************************************
     CONSTRUCTOR    : Q2Student

     DESCRIPTION	: Student constructor. The constructor also make a call to
                      populate an array which represents the student's grades
                      in letter grade format.

     INPUT			: Type			: String
                    : Description	: student name

                    : Type			: String
                    : Description	: student id

                    : Type			: array of type float
                    : Description	: the student's course marks

     OUTPUT			: Type 			: N/A
                    : Description	: N/A
     ******************************************************************************/
    public Q2Student(String n, String i, float[] m){
        name      = n;
        studentId = i;
        marks     = m;
        populateGradesArray();
    }





    /******************************************************************************
     METHOD		    : populateGradesArray

     DESCRIPTION	: This method populates the letterGrades array.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void populateGradesArray() {

        for (int i = 0; i < numberOfCourses; i++)
            letterGrades[i] = convertNumericToLetter(marks[i]);
    }





    /******************************************************************************
     METHOD		    : convertNumericToLetter

     DESCRIPTION	: This method converts numeric grades to letter grades. It
                      records the number of occurrences of each letter grade.

     INPUT			: Type			: float
                    : Description	: numeric grade to convert

     OUTPUT			: Type 			: String
                    : Description	: returns the letter grade.
     ******************************************************************************/
    private String convertNumericToLetter (float grade) {

        // letter grades are indexed by grade point
        // the letter grade is added (+1) to the gradeCount array
        if(grade >= 93 && grade <= 100) { gradeCount[13] += 1; return grades[13]; } // [13] is A+
        if(grade >= 86 && grade < 93)   { gradeCount[12] += 1; return grades[12]; } // [12] is A
        if(grade >= 80 && grade < 86)   { gradeCount[11] += 1; return grades[11]; } // .
        if(grade >= 77 && grade < 80)   { gradeCount[10] += 1; return grades[10]; } // .
        if(grade >= 73 && grade < 77)   { gradeCount[9]  += 1; return grades[9]; }  // .
        if(grade >= 70 && grade < 73)   { gradeCount[8]  += 1; return grades[8]; }  // .
        if(grade >= 67 && grade < 70)   { gradeCount[7]  += 1; return grades[7]; }  // .
        if(grade >= 63 && grade < 67)   { gradeCount[6]  += 1; return grades[6]; }  // .
        if(grade >= 60 && grade < 63)   { gradeCount[5]  += 1; return grades[5]; }  // .
        if(grade >= 57 && grade < 60)   { gradeCount[4]  += 1; return grades[4]; }  // .
        if(grade >= 53 && grade < 57)   { gradeCount[3]  += 1; return grades[3]; }  // .
        if(grade >= 50 && grade < 53)   { gradeCount[2]  += 1; return grades[2]; }  // .
        if(grade >= 35 && grade < 50)   { gradeCount[1]  += 1; return grades[1]; }  // [1] is F
        else { gradeCount[0] += 1; return grades[0]; }                              // [0] is F-
    }





    /******************************************************************************
     METHOD		    : getId

     DESCRIPTION	: This method returns the student's id.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: returns the student's id.
     ******************************************************************************/
    public String getId()   { return studentId; }





    /******************************************************************************
     METHOD		    : getName

     DESCRIPTION	: This method returns the student's name.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: String
                    : Description	: returns the student's full name.
     ******************************************************************************/
    public String getName() { return name; }





    /******************************************************************************
     METHOD		    : getAverage

     DESCRIPTION	: This method calculates the student's average mark.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: int
                    : Description	: returns the student's average mark.
     ******************************************************************************/
    public int getAverage() { return (int)Math.ceil(getSumOfMarks()/ numberOfCourses); }





    /******************************************************************************
     METHOD		    : getSumOfMarks

     DESCRIPTION	: This method calculates the sum of the student's marks. Used
                      in calculating the student's average mark.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: float
                    : Description	: returns the sum of the student's marks.
     ******************************************************************************/
    public float getSumOfMarks() {

        float sum = 0f;
        for (int i = 0; i < numberOfCourses; i++)
            sum += marks[i];
        return sum;
    }





    /******************************************************************************
     METHOD		    : printStudentInfo

     DESCRIPTION	: This method prints the student's info to the console.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    public void printStudentInfo(){
        System.out.println("Name: " + getName());
        System.out.println("Student Id: " + getId());
        printMarks();
        System.out.println("\nAverage " + getAverage() + "%");
        printNumberOfCoursesInEachLetterGradeCategory();
    }





    /******************************************************************************
     METHOD		    : printMarks

     DESCRIPTION	: This method prints the student's marks to the console.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void printMarks() {

        System.out.println("Marks: ");
        for(int i = 0; i < numberOfCourses; i++)
            System.out.println(marks[i] + "%\t" + letterGrades[i]);
    }





    /******************************************************************************
     METHOD		    : printNumberOfCoursesInEachLetterGradeCategory

     DESCRIPTION	: This method prints the number of occurrences of each letter
                      grade to the console.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
    private void printNumberOfCoursesInEachLetterGradeCategory(){

        System.out.println("\nNumber of courses with the following letter grades: ");

        for(int i = grades.length - 1, j = 0; i >= 0; i--, j++) {
            if(j % 3 == 0)  System.out.println(""); // for formatting
            System.out.print(grades[i] +": " + gradeCount[i] + "\t\t");
        }
    }


} // end class Q2Student