package org.learning.spring;

public class GymCoach implements Coach {

	@Override
	public String getDailyWorkout() {
		
		return "Lift dumbell 15 times!";
	}

}
