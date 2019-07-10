/**
 * PROJECT:     Lab 2 - Question 3
 * FILE:        Q3PythagoreanTriples.java
 * AUTHOR:      Jason Choquette 104337378
 * DATE:        January 20, 2017
 * DESCRIPTION: This is an application to find all Pythagorean triples for side1, side2 and the hypotenuse,
 *              all no larger than 500. Must use a triple-nested for loop that tries all possibilities.
 */


// using abstract data structure ArrayList
import java.util.ArrayList;


public class Q3PythagoreanTriples {

    private final static int max   = 500;
    private static ArrayList<Triple> triples = new ArrayList<>(); // used to store all the Pythagorean triples found

    public static void main(String args[]) {

        findTriples();
        for (Triple t : triples)
            System.out.println(t.side1 + " " + t.side2 + " " + t.hypotenuse);

        System.out.println("total Pythagorean Triples found: " + triples.size());
    }





    /******************************************************************************
     METHOD		    : findTriples

     DESCRIPTION	: This method finds Pythagorean triples and stores them in an
                      ArrayList.

     INPUT			: Type			: void
                    : Description	: N/A

     OUTPUT			: Type 			: void
                    : Description	: N/A
     ******************************************************************************/
     private static void findTriples() {

        for(int i = 2; i <= max; i++){
            for(int j = 2; j <= max; j++){
                for(int k = 2; k <= max; k++){
                    int side1      = (int) Math.pow(i, 2);
                    int side2      = (int) Math.pow(j, 2);
                    int hypotenuse = (int) Math.pow(k, 2);
                    if(side1 + side2 == hypotenuse){
                        triples.add(new Triple(side1, side2, hypotenuse));
                    }
                }
            }
        }
    }




    // represents a Pythagorean Triple
    public static class Triple{

        // sides of the triangle
        private int side1;
        private int side2;
        private int hypotenuse;

        /******************************************************************************
         CONSTRUCTOR    : Triple

         DESCRIPTION	: Triple constructor. Used as a data type to represent
                          Pythagorean triples.

         INPUT			: Type			: int
                        : Description	: side 1

                        : Type			: int
                        : Description	: side 2

                        : Type			: int
                        : Description	: hypotenuse

         OUTPUT			: Type 			: N/A
                        : Description	: N/A
         ******************************************************************************/
        Triple(int s1, int s2, int h){
            side1       = (int) Math.sqrt(s1);
            side2       = (int) Math.sqrt(s2);
            hypotenuse  = (int) Math.sqrt(h);
        }
    }

} // end class Q3PythagoreanTriples
