package org.learning.spring;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
//import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
//@Scope("prototype")
public class BoxingCoach implements Coach {

	@Autowired // no need of any setter or constructor to inject
	@Qualifier("fileFortuneService")
	private FortuneService fortuneService;

	@Value("${foo.email}")
	private String email;

	@Value("${foo.team}")
	private String team;
	/*
	 * @Autowired public BoxingCoach(FortuneService theFortuneService) {
	 * fortuneService = theFortuneService; }
	 */

	public BoxingCoach() {
		System.out.println(">> BoxingCoach: inside default constructor");
	}
	
	// define my init method
	@PostConstruct
	public void doMyStartupStuff() {
		System.out.println(">> BoxingCoach: inside of doMyStartupStuff()");
	}
	
	// define my destroy method
	@PreDestroy
	public void doMyCleanupStuff() {
		System.out.println(">> BoxingCoach: inside of doMyCleanupStuff()");
	}

	@Override
	public String getDailyWorkout() {
		return "Hit dummy 50 times! \nYour team is: " + team + "\nYour email: " + email;
	}

	public String getEmail() {
		return email;
	}

	public String getTeam() {
		return team;
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}

}
