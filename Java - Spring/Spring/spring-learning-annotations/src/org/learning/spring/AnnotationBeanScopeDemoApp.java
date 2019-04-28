package org.learning.spring;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AnnotationBeanScopeDemoApp {

	public static void main(String[] args) {

		// load spring config file
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");

		// retrieve bean from spring container
		Coach theCoach = context.getBean("boxingCoach", Coach.class);

		Coach alphaCoach = context.getBean("boxingCoach", Coach.class);

		// check if they are the same
		boolean result = (theCoach == alphaCoach);
		
		// print out the results
		System.out.println("\nPointing to the same objct: " + result);
		
		System.out.println("\nMemory location for theCoach: " + theCoach);
		
		System.out.println("\nMemory location for alphaCoach: " + alphaCoach);
		
		// close the context
		context.close();
	}

}
