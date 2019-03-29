/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.test;

import static org.hamcrest.CoreMatchers.instanceOf;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.CoreMatchers.startsWith;
import org.junit.Assert;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertThat;
import static org.junit.Assert.fail;
import org.junit.Before;
import org.junit.Test;
import pl.model.DiceException;
import pl.model.Model;

/**
 * Model Test class, tests model
 *
 * @author Szymon Szpakowski
 * @version 2.1
 */
public class RollOfDiceModelTest {

    /**
     * Field represents tested object
     */
    Model model;

    /**
     * Sets model with correct values
     */
    @Before
    public void setup() {
        model = new Model();
        model.setNumOfDices(3);
        model.setNumOfWalls(6);
        model.setMode("sum");

    }

    /**
     * Tests if reference is correct
     */
    @Test
    public void testReference() {
        Model model2 = new Model();
        assertNotSame("If objects refere to the same object", model, model2);

        model2 = model;
        assertSame("Objects should refere to the same object", model, model2);
    }

    /**
     * Tests correct number of dices (should be 1 or more)
     */
    @Test
    public void testNumOfDices() {
        model.setNumOfDices(1);
        try {
            model.throwDices();
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        model.setNumOfDices(0);
        try {
            model.throwDices();
            fail("An exception should be thrown when numberOfDices is less than 1");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

        model.setNumOfDices(-40);
        try {
            model.throwDices();
            fail("An exception should be thrown when numberOfDices is less than 1(also non-positive)");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        model.setNumOfDices(null);
        Assert.assertNull(model.getNumOfDices());
       try {
            model.throwDices();
            fail("An exception should be thrown when numberOfDices is null");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    /**
     * Tests number of walls (shuold be 4 or more)
     */
    @Test
    public void testNumOfWalls() {
        model.setNumOfWalls(4);
        try {
            model.throwDices();
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

        model.setNumOfWalls(3);
        try {
            model.throwDices();
            fail("An exception should be thrown when numberOfWalls is less than 4");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

        model.setNumOfWalls(-455555554);
        try {
            model.throwDices();
            fail("An exception should be thrown when numberOfWalls is less than 4(also non-positive)");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        model.setNumOfWalls(null);
        Assert.assertNull(model.getNumOfWalls());
       try {
            model.throwDices();
            fail("An exception should be thrown when numberOfWalls is null");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    /**
     * Tests mode (should be "max" or "sum")
     */
    @Test
    public void testMode() {
        model.setMode("max");
        try {
            model.throwDices();
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

        model.setMode("sum");
        try {
            model.throwDices();
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }

        model.setMode("wrong");
        try {
            model.throwDices();
            fail("An exception should be thrown when mode is other than 'sum' or 'max' ");
        } catch (DiceException ex) {
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /**
     * Tests correct message of exception
     */
    @Test
    public void testException() {
        Exception exception = null;

        model.setMode("3");
        try {
            model.throwDices();
        } catch (DiceException ex) {
            exception = ex;
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        assertThat("Wrong type of the exception!", exception, is(instanceOf(DiceException.class)));
        assertThat("Unexpected message!", exception.getMessage(), startsWith("Wrong throw mode"));

        model.setMode("max");
        model.setNumOfDices(-3);
        try {
            model.throwDices();
        } catch (DiceException ex) {
            exception = ex;
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        assertThat("Wrong type of the exception!", exception, is(instanceOf(DiceException.class)));
        assertThat("Unexpected message!", exception.getMessage(), startsWith("Wrong numeber of dices"));

        model.setNumOfDices(3);
        model.setNumOfWalls(3);
        try {
            model.throwDices();
        } catch (DiceException ex) {
            exception = ex;
            //Logger.getLogger(RollOfDiceModelTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        assertThat("Wrong type of the exception!", exception, is(instanceOf(DiceException.class)));
        assertThat("Unexpected message!", exception.getMessage(), startsWith("Wrong numeber of walls"));

    }

}
