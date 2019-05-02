/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package firmakurierska;

import Modele.SendPackage;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

/**
 * FXML Controller class
 *
 * @author Szymon
 */
public class SendPackageController {

    private AllControllers allControllers = AllControllers.getInstance();

    @FXML
    private TextField sName;
    @FXML
    private TextField sSurname;
    @FXML
    private TextField sStreet;
    @FXML
    private TextField sHouseNumber;
    @FXML
    private TextField sLocalNumber;
    @FXML
    private TextField sPhoneNumber;
    @FXML
    private TextField sEmail;

    @FXML
    private TextField rName;
    @FXML
    private TextField rSurname;
    @FXML
    private TextField rStreet;
    @FXML
    private TextField rHouseNumber;
    @FXML
    private TextField rLocalNumber;
    @FXML
    private TextField rPhoneNumber;
    @FXML
    private TextField rEmail;

    @FXML
    private TextField length;
    @FXML
    private TextField width;
    @FXML
    private TextField height;
    @FXML
    private TextField weight;

    @FXML
    private Label incorrectNameN;
    @FXML
    private Label incorrectSurNameN;
    @FXML
    private Label incorrectStreetN;
    @FXML
    private Label incorrectHomeN;
    @FXML
    private Label incorrectLocalN;
    @FXML
    private Label incorrectPhoneN;
    @FXML
    private Label incorrectEmailN;
    @FXML
    private Label incorrectNameO;
    @FXML
    private Label incorrectSurNameO;
    @FXML
    private Label incorrectStreetO;
    @FXML
    private Label incorrectHomeO;
    @FXML
    private Label incorrectLocalO;
    @FXML
    private Label incorrectPhoneO;
    @FXML
    private Label incorrectEmailO;
    @FXML
    private Label incorrectLength;
    @FXML
    private Label incorrectWidth;
    @FXML
    private Label incorrectHeigth;
    @FXML
    private Label incorrectWeigth;

    /**
     * checks if parameter is INTEGER
     *
     * @param s
     * @return
     */
    public static boolean isInteger(String s) {
        return isInteger(s, 10);
    }

    /**
     * checks if parameter is INTEGER
     *
     * @param s
     * @param radix
     * @return
     */
    public static boolean isInteger(String s, int radix) {
        if (s.isEmpty()) {
            return false;
        }
        for (int i = 0; i < s.length(); i++) {
            /*if (i == 0 && s.charAt(i) == '-') {
                if (s.length() == 1) {
                    return false;
                } else {
                    continue;
                }
            }*/
            if (Character.digit(s.charAt(i), radix) < 0) {
                return false;
            }
        }
        return true;
    }

    private void initialize() {
        allControllers.setSendPackageController(this);
    }

    @FXML
    private void generateAndSend() {
        SendPackage sendPackage = new SendPackage();
        int ID = allControllers.getSignInController().getUserID();

        incorrectNameN.setText("");
        incorrectSurNameN.setText("");
        incorrectStreetN.setText("");
        incorrectHomeN.setText("");
        incorrectLocalN.setText("");
        incorrectPhoneN.setText("");
        incorrectEmailN.setText("");
        incorrectNameO.setText("");
        incorrectSurNameO.setText("");
        incorrectHomeO.setText("");
        incorrectStreetO.setText("");
        incorrectLocalO.setText("");
        incorrectPhoneO.setText("");
        incorrectEmailO.setText("");
        incorrectWidth.setText("");
        incorrectLength.setText("");
        incorrectHeigth.setText("");
        incorrectWeigth.setText("");

        if (!sName.getText().matches("[\\p{Lu}\\p{Ll}]{1,50}")) {
            incorrectNameN.setText("BŁĘDNE IMIĘ");
        } else if (!sSurname.getText().matches("[\\p{Lu}\\p{Ll}-]{1,50}")) {
            incorrectSurNameN.setText("BŁĘDNE NAZWISKO");
        } else if (!sStreet.getText().matches("[\\p{Lu}\\p{Ll}- ]{1,50}")) {
            incorrectStreetN.setText("BŁĘDNA ULICA");
        } else if (!isInteger(sHouseNumber.getText())) {
            incorrectHomeN.setText("BŁĘDNY NUMER DOMU");
        } else if (!isInteger(sLocalNumber.getText()) && sLocalNumber.getText().length() > 0) {
            incorrectLocalN.setText("BŁĘDNY NR LOKALU");
        } else if (!isInteger(sPhoneNumber.getText()) || sPhoneNumber.getText().length() < 3) {
            incorrectPhoneN.setText("BŁĘDNY NR TEL");
        } else if (!sEmail.getText().matches("\\w+@\\w+\\.\\w{1,3}") || sEmail.getText().length() > 50) {
            incorrectEmailN.setText("BŁĘDNY EMAIL");
        } else if (!rName.getText().matches("[\\p{Lu}\\p{Ll}]{1,50}")) {
            incorrectNameO.setText("BŁĘDNE IMIĘ");
        } else if (!rSurname.getText().matches("[\\p{Lu}\\p{Ll}][\\p{Lu}\\p{Ll}-]{1,48}[\\p{Lu}\\p{Ll}]")) {
            incorrectSurNameO.setText("BŁĘDNE NAZWISKO");
        } else if (!rStreet.getText().matches("[\\p{Lu}\\p{Ll}- ]{1,50}")) {
            incorrectStreetO.setText("BŁĘDNA ULICA");
        } else if (!isInteger(rHouseNumber.getText()) || rHouseNumber.getText().length() < 1) {
            incorrectHomeO.setText("BŁĘDNY NUMER DOMU");
        } else if (!isInteger(rLocalNumber.getText()) && sLocalNumber.getText().length() > 0) {
            incorrectLocalO.setText("BŁĘDNY NR LOKALU");
        } else if (!isInteger(rPhoneNumber.getText()) || rPhoneNumber.getText().length() < 3) {
            incorrectPhoneO.setText("BŁĘDNY NR TEL");
        } else if (!rEmail.getText().matches("\\w+@\\w+\\.\\w{1,3}") || sEmail.getText().length() > 50) {
            incorrectEmailO.setText("BŁĘDNY EMAIL");
        } else if (!isInteger(length.getText()) || length.getText().length() < 1) {
            incorrectLength.setText("BŁĘDNA DŁUGOŚĆ");
        } else if (isInteger(length.getText()) && Integer.parseInt(length.getText()) > 200) {
            incorrectLength.setText("PACZKA ZBYT DŁUGA (max 200cm)");
        } else if (!isInteger(width.getText()) || width.getText().length() < 1) {
            incorrectWidth.setText("BŁĘDNA SZEROKOŚĆ");
        } else if (isInteger(width.getText()) && Integer.parseInt(width.getText()) > 200) {
            incorrectWidth.setText("PACZKA ZBYT SZEROKA (max 200cm)");
        } else if (!isInteger(height.getText()) || height.getText().length() < 1) {
            incorrectHeigth.setText("BŁĘDNA WYSOKOŚĆ");
        } else if (isInteger(height.getText()) && Integer.parseInt(height.getText()) > 100) {
            incorrectHeigth.setText("PACZKA ZBYT WYSOKA (max 100cm)");
        } else if (!isInteger(weight.getText()) || weight.getText().length() < 1) {
            incorrectWeigth.setText("BŁĘDNY CIĘŻAR");
        } else if (isInteger(weight.getText()) && Integer.parseInt(weight.getText()) > 50) {
            incorrectWeigth.setText("PACZKA ZBYT CIĘŻKA (max 50kg)");
        } else {
            sendPackage.addPackageToDatabase(sName.getText(), sSurname.getText(), sStreet.getText(), sHouseNumber.getText(), sLocalNumber.getText(), sPhoneNumber.getText(), sEmail.getText(),
                    rName.getText(), rSurname.getText(), rStreet.getText(), rHouseNumber.getText(), rLocalNumber.getText(), rPhoneNumber.getText(), rEmail.getText(),
                    length.getText(), width.getText(), height.getText(), weight.getText(), ID);
            sendPackage.generateCard(sName.getText(), sSurname.getText(), sStreet.getText(), sHouseNumber.getText(), sLocalNumber.getText(), sPhoneNumber.getText(), sEmail.getText(),
                    rName.getText(), rSurname.getText(), rStreet.getText(), rHouseNumber.getText(), rLocalNumber.getText(), rPhoneNumber.getText(), rEmail.getText(),
                    length.getText(), width.getText(), height.getText(), weight.getText());
            sName.setText("");
            sSurname.setText("");
            sStreet.setText("");
            sHouseNumber.setText("");
            sLocalNumber.setText("");
            sPhoneNumber.setText("");
            sEmail.setText("");
            rName.setText("");
            rSurname.setText("");
            rStreet.setText("");
            rHouseNumber.setText("");
            rLocalNumber.setText("");
            rPhoneNumber.setText("");
            rEmail.setText("");
            width.setText("");
            length.setText("");
            height.setText("");
            weight.setText("");

        }

    }

}
