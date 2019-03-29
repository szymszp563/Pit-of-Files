/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pl.model;


  /** my own exception class to be thrown in logic(model) and catch in controller
  * @author oem
  */
    public class DiceException extends Exception {

        DiceException() {
        }

        public DiceException(String message) {
            super(message);
        }
    }
