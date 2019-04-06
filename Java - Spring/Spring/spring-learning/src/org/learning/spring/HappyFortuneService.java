package org.learning.spring;

import java.util.Random;

public class HappyFortuneService implements FortuneService {
	
	private String[] fortunes;
		
	public String[] getFortunes() {
		return fortunes;
	}

	public void setFortunes(String[] fortunes) {
		System.out.println("HappyFortuneService: inside setter method - setFortunes");
		this.fortunes = fortunes;
	}

	@Override
	public String getFortune() {
		return fortunes[(new Random().nextInt(3))];
	}

}
