/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pl.model;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

/**
 * Model clss represensts an object and has logic of application.
 *
 * @author Szymon Szpakowski
 * @version 2.1
 */
public class Model implements ModelGetInterface {

    /**
     * field represents numer of dices to throw
     */
    private Integer numOfDices;
    /**
     * field represents number of walls of each dice
     */
    private Integer numOfWalls;
    /**
     * field represents mode of logic
     */
    private String mode;
    /**
     * field represents result of logic
     */
    private Integer result = 0;
    /**
     * field represents safe collection, added in version 2.1
     */
    private List<Integer> generatedThrows = new LinkedList<>();

    /**
     * getter of number of dices
     *
     * @return number of dices
     */
    @Override
    public Integer getNumOfDices() {
        return numOfDices;
    }

    /**
     * getter of number of walls
     *
     * @return number of walls
     */
    @Override
    public Integer getNumOfWalls() {
        return numOfWalls;
    }

    /**
     * getter of mode
     *
     * @return mode
     */
    @Override
    public String getMode() {
        return mode;
    }

    /**
     * getter of result
     *
     * @return result
     */
    @Override
    public Integer getResult() {
        return result;
    }

    /**
     * setter of number of dices
     *
     * @param numOfDices number of dices
     */
    public void setNumOfDices(Integer numOfDices) {
        this.numOfDices = numOfDices;
    }

    /**
     * setter of number of walls
     *
     * @param numOfWalls number of walls
     */
    public void setNumOfWalls(Integer numOfWalls) {
        this.numOfWalls = numOfWalls;
    }

    /**
     * setter of mode
     *
     * @param mode mode of logic
     */
    public void setMode(String mode) {
        this.mode = mode;
    }

    /**
     * logic of model, depending on mode sets result as sum of throw dices or
     * maximum of thrown dices. In version 2.1 added forEach loop and generic
     * type box(which calculates max value)
     *
     * @throws DiceException thrown when mode or number of dices or number of
     * walls is wrong
     */
    public void throwDices() throws DiceException {
        /**
         * generator of random numbers(in this case integer numbers >1)
         */
        Random generator = new Random();
        /**
         * mode of logic
         */
        String modeOfRun = this.getMode();

        if (!modeOfRun.equals("sum") && !modeOfRun.equals("max")) {
            throw new DiceException("Wrong throw mode!!! Third argument should be 'max' or 'sum'!");
        } else if (this.getNumOfDices() == null) {
            throw new DiceException("Number of dices is NULL!!! Number of dices should equals 1 or more!");
        } else if (this.getNumOfWalls() == null) {
            throw new DiceException("Number of walls is NULL!!! Number of dices should equals 4 or more!");
        } else if (this.getNumOfDices() < 1) {
            throw new DiceException("Wrong numeber of dices!!! Number of dices should equals 1 or more!");
        } else if (this.getNumOfWalls() < 4) {
            throw new DiceException("Wrong numeber of walls!!! Number of walls should equals 4 or more!");
        } else {
            for (int i = 0; i < this.getNumOfDices(); i++) {
                generatedThrows.add((generator.nextInt(this.getNumOfWalls()) + 1));
            }
            if (modeOfRun.equals("sum")) {
                //result += (generator.nextInt(this.getNumOfWalls()) + 1);
                for (Integer number : generatedThrows) {
                    result += number;
                }
            } else if (modeOfRun.equals("max")) {
                BoxOfThrowedNumbers<Integer> box = new BoxOfThrowedNumbers<>(generatedThrows);
                result = box.max();
                //for (int i = 0; i < this.getNumOfDices(); i++) {
                //    int buff = (generator.nextInt(this.getNumOfWalls()) + 1);
                //    if (this.result < buff) {
                //        this.result = buff;
                //    }
                //}
            }
        }
    }

}

/**
 * added in version 2.1 to show usage of standard annotations
 *
 */
interface ModelGetInterface {

    public Integer getNumOfDices();

    public Integer getNumOfWalls();

    public String getMode();

    public Integer getResult();
}

/**
 *
 * added in vesion 2.1 to show usage of generic type
 *
 * @param <N>
 */
class BoxOfThrowedNumbers<N extends Number> {

    List<N> contents;

    BoxOfThrowedNumbers(List<N> generatedThrows) {
        contents = generatedThrows;
    }

    /**
     *
     * @return max number of throws
     */
    public int max() {
        int max = 0;
        Iterator<N> i = contents.iterator();
        while (i.hasNext()) {
            int buff = ((Integer) i.next());
            if (max < buff) {
                max = buff;
            }
        }
        return max;
    }
}
