package pack.builder;

import jakarta.inject.Qualifier;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import static java.lang.annotation.ElementType.FIELD;
import static java.lang.annotation.ElementType.METHOD;


@Qualifier
@Retention(RetentionPolicy.RUNTIME)
@Target({ FIELD, METHOD })
public @interface Built {}