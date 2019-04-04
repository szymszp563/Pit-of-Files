package org.learning.spring;

public class TrackCoach implements Coach {

	private FortuneService fortuneService;
	
	TrackCoach() {
	}
	
	public TrackCoach(FortuneService fortuneService) {
		this.fortuneService = fortuneService;
	}
	
	@Override
	public String getDailyWorkout() {

		return "Run 5000 km";
	}

	@Override
	public String getDailyFortune() {

		return fortuneService.getFortune();
	}

}
