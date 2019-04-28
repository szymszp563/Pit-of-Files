package org.learning.spring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
public class BoxingCoach implements Coach {

	@Autowired//no need of any setter or constructor to inject
	@Qualifier("happyFortuneService")
	private FortuneService fortuneService;
	/*
	@Autowired
	public BoxingCoach(FortuneService theFortuneService) {
		fortuneService = theFortuneService;
	}
	*/
	@Override
	public String getDailyWorkout() {
		return "Hit dummy 50 times!";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}

}
