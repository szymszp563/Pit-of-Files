/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.controller;

import pl.view.View;
import pl.model.DiceException;
import pl.model.Model;
import java.util.Scanner;

/**
 * Controller class acts on model and view
 * controls datta flow into model and updates view.
 * Keeps view and model separate.
 * In version 2.1 changed method setModel() to be private
 * @author Szymon Szpakowski
 * @version 2.1
 */
public class Controller {
    /**model field of controller to act on model*/
    private Model model;
    /**view field of controller to act on view*/
    private View view;
    /**arguments passed in command line*/
    private String args[] = new String[3];
    /**error field, if false lets logic work*/
    boolean error = false;

    /**
     * constructor of controller, sets fields of controller and also sets model
     * @param model represents model in controller
     * @param view represents view in controller
     * @param args arguments passed in command line
     */
    public Controller(Model model, View view, String args[]) {
        this.model = model;
        this.view = view;
        this.args = args;

        this.setModel();
    }

    /**
     * Sets fields of model which should be passed in command line.
     * If there are no arguments in command line then asks user to write them, 
     * verify them and set in model.
     * If arguments are passed in command line verifies them and set in model.
     * 
     */
    private void setModel() {

        if (this.args.length == 0) {
            /**Scanner used to pass data for fields of model if no arguments passed in command line.*/
            Scanner scanner = new Scanner(System.in);

            try {
                view.printMessage("Enter number of dices(1 or more): ");
                model.setNumOfDices(Integer.parseInt(scanner.next()));
                view.printMessage("Enter number of walls(4 or more): ");
                model.setNumOfWalls(Integer.parseInt(scanner.next()));
                view.printMessage("Enter mode('sum' or 'max'): ");
                model.setMode(scanner.next());
            } catch (NumberFormatException ex) {
                view.printError("No numbers of type int!!! First and second argument should be of type int!");
                this.error = true;
            }

        } else {

            try {
                model.setNumOfDices(Integer.parseInt(this.args[0]));
                model.setNumOfWalls(Integer.parseInt(this.args[1]));
                model.setMode(this.args[2]);
            } catch (ArrayIndexOutOfBoundsException ex) {
                view.printError("Too few arguments!!!");
                this.error = true;
            } catch (NumberFormatException ex) {
                view.printError("No numbers of type int!!! First and second argument should be of type int!");
                this.error = true;
            }
           
        }
    }

    /**
     * method starts(if no errors occured) logic from model
     * uses my own exception implemented in model
     */
    public void throwDices() {
        
        if (!this.error) {
            try {
                model.throwDices();
                if(model.getMode().equals("max"))
                    view.printMaxNum(model.getResult());
                else
                    view.printSum(model.getResult());
            } catch (DiceException ex) {
                view.printError(ex.getMessage());
            }
        }
    }

}
