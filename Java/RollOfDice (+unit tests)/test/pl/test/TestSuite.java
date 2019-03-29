/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.test;

/**
 *
 * @author oem
 */
import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

/**
 * Sample test suite indicting the test engine and classes containg unit tests.
 *
 * @author Gall Anonim
 * @version 1.0
 */
@RunWith(Suite.class)
@SuiteClasses({
    RollOfDiceModelTest.class})
public class TestSuite {
}
