javac.exe WEB-INF\classes\pack\model\api\dto\*.java               -classpath ".\WEB-INF\classes"
javac.exe WEB-INF\classes\pack\model\api\in\*.java                 -classpath ".\WEB-INF\classes"
javac.exe WEB-INF\classes\pack\model\api\out\*.java           -classpath ".\WEB-INF\classes"

javac.exe WEB-INF\classes\pack\model\*.java                         -classpath ".\WEB-INF\classes"



javac.exe WEB-INF\classes\pack\builder\*.java                       -classpath ".\WEB-INF\classes;D:\glassfish6\glassfish\lib\javaee.jar;D:\glassfish6\glassfish\modules\jakarta.enterprise.cdi-api.jar"

javac.exe WEB-INF\classes\pack\repository\basket\*.java                  -classpath ".\WEB-INF\classes;D:\glassfish6\glassfish\lib\javaee.jar;D:\glassfish6\glassfish\modules\jakarta.persistence-api.jar"
javac.exe WEB-INF\classes\pack\repository\user\*.java                  -classpath ".\WEB-INF\classes;D:\glassfish6\glassfish\lib\javaee.jar;D:\glassfish6\glassfish\modules\jakarta.persistence-api.jar"
javac.exe WEB-INF\classes\pack\repository\product\*.java                  -classpath ".\WEB-INF\classes;D:\glassfish6\glassfish\lib\javaee.jar;D:\glassfish6\glassfish\modules\jakarta.persistence-api.jar"


javac.exe WEB-INF\classes\pack\controller\path\Controller.java          -classpath ".\WEB-INF\classes;D:\glassfish6\glassfish\lib\javaee.jar"
javac.exe WEB-INF\classes\pack\controller\config\Config.java            -classpath ".\WEB-INF\classes;D:\glassfish6\glassfish\lib\javaee.jar"


pause