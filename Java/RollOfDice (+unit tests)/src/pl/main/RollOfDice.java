/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.main;

import pl.controller.Controller;
import pl.view.View;
import pl.model.Model;

/**
 * main class of program
 * @author Szymon Szpakowski
 * @version 1.1
 */
public class RollOfDice {

    /**
     * @param args the command line arguments, first arg - number of dices(1 or
     * more) sercond arg - number of walls of dices(more than 3) third - mode
     * (sum or max)
     */
    public static void main(String[] args) {
        
        Model model = new Model();

        View view = new View();

        Controller controller = new Controller(model, view, args);
        controller.throwDices();
    }

}
