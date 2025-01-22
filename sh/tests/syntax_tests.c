#include "tests.h"

void	test_syntax()
{
	assert(is_correct_syntax("echo Hello") == true);
	assert(is_correct_syntax("<echo Hello") == false);
	assert(is_correct_syntax("echo Hello>") == false);
	assert(is_correct_syntax(")echo Hello") == false);
	assert(is_correct_syntax("echo Hello>") == false);
	assert(is_correct_syntax("|echo Hello") == false);
	assert(is_correct_syntax("echo Hello|") == false);
	assert(is_correct_syntax("") == true);
	assert(is_correct_syntax("echo \'") == true);
	assert(is_correct_syntax("echo \"") == true);
	assert(is_correct_syntax("echo \'Hello\' \'world") == true);
	assert(is_correct_syntax("echo \"Hello\" \"world,\" \"how are you?") == true);
	assert(is_correct_syntax("echo \'Hello\' \"world\" \"how\" are \'you\'") == true);
	assert(is_correct_syntax("echo \'Hello \"world\" \"how are \'you\'") == true);
	assert(is_correct_syntax("echo \'Hello\' world\" \"how\" are \'you\'") == true);
	assert(is_correct_syntax("echo \'Hello\' world\" \"how\" are you\'") == true);
	assert(is_correct_syntax("echo \"This is \\\"a test\\\" example\"") == true);
	assert(is_correct_syntax("echo \"This is \\\"a test\\\" example") == true);
	assert(is_correct_syntax("echo 'Hello,    world!'") == true);
	assert(is_correct_syntax("echo 'This is a \"nested quote\" inside'") == true);
	assert(is_correct_syntax("echo 'This is a \"nested quote inside'") == true);
	assert(is_correct_syntax("echo \"This 'is' a 'test' of 'quotes'\"") == true);
	assert(is_correct_syntax("   echo    'Hello   world'   ") == true);
	assert(is_correct_syntax("echo 'Hello' > 'filename.txt'") == true);
	assert(is_correct_syntax("echo This is a backslash \\\\") == true);

	ft_printf("Alle Tests in test_is_correct_syntax erfolgreich.\n");
}
