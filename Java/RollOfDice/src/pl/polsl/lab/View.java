/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.lab;

/**
 * View class - represents the visualization of the data that mdel contains.
 * @author Szymon Szpakowski
 * @version 1.1
 */
public class View {
    //prints maximum number of thown dices(if 'max' mode selected)
    public void printMaxNum(Integer maxNum) {
        System.out.println("Max number of your rolls is: " + maxNum);
    }
    //prints sum of numbers of thown dices(if 'sum' mode selected)
    public void printSum(Integer sum) {
        System.out.println("Sum of your rolls is: " + sum);
    }
    //prints messages
    public void printMessage(String message){
        System.out.print(message);
    }
    //prints errors
    public void printError(String message){
        System.err.println(message);
    }
    
}
