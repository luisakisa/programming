package pack.model.api.dto;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.util.Arrays;
import java.util.Random;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;

public class Password {

        private static final Random RANDOM = new SecureRandom();
        private static final int ITERATIONS = 10000;
        private static final int KEY_LENGTH = 256;
        public byte[]  salt;
        public  byte[] passSalt;
      
        public Password() {
            salt = getNextSalt();
         }
      
        public static byte[] getNextSalt() {
          byte[] salt = new byte[16];
          RANDOM.nextBytes(salt);
          return salt;
        }
      
        public byte[] hash(char[] password) {
          PBEKeySpec spec = new PBEKeySpec(password, salt, ITERATIONS, KEY_LENGTH);
          Arrays.fill(password, Character.MIN_VALUE);
          try {
            SecretKeyFactory skf = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA1");
            passSalt = skf.generateSecret(spec).getEncoded();
            return skf.generateSecret(spec).getEncoded();
          } catch (NoSuchAlgorithmException | InvalidKeySpecException e) {
            throw new AssertionError("Error while hashing a password: " + e.getMessage(), e);
          } finally {
            spec.clearPassword();
          }
        }
      
        public  boolean isExpectedPassword(char[] password) {
          byte[] pwdHash = hash(password);
          Arrays.fill(password, Character.MIN_VALUE);
          if (pwdHash.length != passSalt.length) return false;
          for (int i = 0; i < pwdHash.length; i++) {
            if (pwdHash[i] != passSalt[i]) return false;
          }
          return true;
        }
      }

