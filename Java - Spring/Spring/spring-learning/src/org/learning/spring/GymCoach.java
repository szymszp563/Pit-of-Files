package org.learning.spring;

public class GymCoach implements Coach {

	private FortuneService fortuneService;
	
	
	GymCoach() {
	}
	public GymCoach(FortuneService fortuneService) {
		this.fortuneService = fortuneService;
	}

	

	@Override
	public String getDailyWorkout() {
		
		return "Lift dumbell 15 times!";
	}

	@Override
	public String getDailyFortune() {

		return fortuneService.getFortune() + " You will lift your best!";
	}

}
