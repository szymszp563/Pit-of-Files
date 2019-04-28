package org.learning.spring;

import java.util.Random;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class FileFortuneService implements FortuneService {

	private String[] fortunes;
	
	@Value("${foo.f1}")
	private String f1;
	
	@Value("${foo.f2}")
	private String f2;
	
	@Value("${foo.f3}")
	private String f3;
	
	@Value("${foo.f4}")
	private String f4;
	
	private Random myRandom = new Random();

	@PostConstruct
	public void setputMyFortunes() {
		fortunes = new String[4];
		fortunes[0]=f1;
		fortunes[1]=f2;
		fortunes[2]=f3;
		fortunes[3]=f4;
		
	}

	@Override
	public String getFortune() {
		String randomFortune = fortunes[myRandom.nextInt(fortunes.length)];
		return randomFortune;
	}

}
