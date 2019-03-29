/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.polsl.lab;

import java.util.Random;

/**
 * Model clss represensts an object and has logic of application. 
 * @author Szymon Szpakowski
 * @version 1.1
 */
public class Model {
    /**
     * field represents numer of dices to throw
     */
    private Integer numOfDices;
    /**field represents number of walls of each dice*/
    private Integer numOfWalls;
    /**field represents mode of logic*/
    private String mode;
    /**field represents result of logic*/
    private Integer result = 0;
    /**
     * getter of number of dices
     * @return number of dices
     */
    public Integer getNumOfDices() {
        return numOfDices;
    }
    /**
     * getter of number of walls
     * @return number of walls
     */
    public Integer getNumOfWalls() {
        return numOfWalls;
    }
    /**
     * getter of mode
     * @return mode
     */
    public String getMode() {
        return mode;
    }
  
    /**
     * getter of result
     * @return result
     */
    public Integer getResult(){
        return result;
    }
    /**
     * setter of number of dices
     * @param numOfDices number of dices
     */
    public void setNumOfDices(Integer numOfDices) {
        this.numOfDices = numOfDices;
    }
    /**
     * setter of number of walls
     * @param numOfWalls number of walls
     */
    public void setNumOfWalls(Integer numOfWalls) {
        this.numOfWalls = numOfWalls;
    }
    /**
     * setter of mode
     * @param mode mode of logic
     */
    public void setMode(String mode) {
        this.mode = mode;
    }
    
   
    
    /**
     * logic of model, depending on mode sets result as sum of throw dices 
     * or maximum of thrown dices
     * @throws DiceException thrown when mode or number of dices or number of walls is wrong
     */
     
    public void throwDices() throws DiceException {
        /**generator of random numbers(in this case integer numbers >1)*/
        Random generator = new Random();
        /**mode of logic*/
        String mode = this.getMode();

        if (!mode.equals("sum") && !mode.equals("max")) {
            throw new DiceException("Wrong throw mode!!! Third argument should be 'max' or 'sum'!");
        } else if (this.getNumOfDices() < 1) {
            throw new DiceException("Wrong numeber of dices!!! Number of dices should equals 1 or more!");
        } else if (this.getNumOfWalls() < 4) {
            throw new DiceException("Wrong numeber of walls!!! Number of walls should equals 4 or more!");
        } else {
            if (mode.equals("sum")) {
                for (int i = 0; i < this.getNumOfDices(); i++) {
                    result += (generator.nextInt(this.getNumOfWalls()) + 1);
                }
            } else if (mode.equals("max")) {
                for (int i = 0; i < this.getNumOfDices(); i++) {
                    int buff = (generator.nextInt(this.getNumOfWalls()) + 1);
                    if (this.result < buff) {
                        this.result = buff;
                    }
                }
            }
        }
    }

}
