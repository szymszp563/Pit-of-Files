package org.learning.spring;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SetterDemoApp {

	public static void main(String[] args) {

		// load the spring configuration file
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");

		// retrieve bean from spring container
		CricketCoach theCoach = context.getBean("myCricketCoach", CricketCoach.class);

		// call methods on the bean
		System.out.println(theCoach.getDailyWorkout());
		System.out.println(theCoach.getDailyFortune());

		// call new methods to get literal values
		System.out.println(theCoach.getEmailAddress());
		System.out.println(theCoach.getTeam());

		// close the context
		context.close();

		/*Boolean b1 = new Boolean("true");
		Boolean b2 = new Boolean("true");
		System.out.println("1. " + b1);
		System.out.println("2. " + b2);
		System.out.println("3. " + (b1 == b2));
		System.out.println("4. " + (true == true));
		System.out.println("5. " + (new Boolean("true") == true));
		System.out.println("6. " + (new Boolean("true") == new Boolean("true")));
		System.out.println("7. " + (b1 == true));
		System.out.println("8. " + (b2 == true));
		System.out.println("9. " + (b2 == true == true == b1));
		System.out.println("10. " + (b2 == true == b1));
		System.out.println("11. " + (b2 == b2 == b1));
		System.out.println("12. " + (b2 == b1));
		System.out.println("13. " + (1 == 1));
		System.out.println("14. " + (new Integer(1) == 1));
		System.out.println("15. " + (new Integer(1) == new Integer(1)));*/
		/*
		Integer i1 = 5;
		Integer i2;
		i2=i1;
		System.out.println(i1==i2);
		i1++;//i2++ to samo
		System.out.println(i1==i2);
		*/
	}

}
