#include "tests.h"

void	test_syntax()
{
	// Testfall 1: Gültiger Befehl
	assert(is_correct_syntax("echo Hello") == true);

	// Testfall 2: Ungültiger Befehl mit ungültigem Zeichen am Anfang
	assert(is_correct_syntax("<echo Hello") == false);

	// Testfall 3: Ungültiger Befehl mit ungültigem Zeichen am Ende
	assert(is_correct_syntax("echo Hello>") == false);

	// Testfall 4: Leerer String
	assert(is_correct_syntax("") == false);

	// Testfall 5: Nur ein '
	assert(is_correct_syntax("echo \'") == false);

	// Testfall 6: Nur ein "
	assert(is_correct_syntax("echo \"") == false);

	// Testfall 7: Nur ungerade '
	assert(is_correct_syntax("echo \'Hello\' \'world") == false);

	// Testfall 8: Nur ungerade ""
	assert(is_correct_syntax("echo \"Hello\" \"world,\" \"how are you?") == false);

	// Testfall 9: Gemischt gerade
	assert(is_correct_syntax("echo \'Hello\' \"world\" \"how\" are \'you\'") == true);

	// Testfall 10: Gemischt ungerade '
	assert(is_correct_syntax("echo \'Hello \"world\" \"how are \'you\'") == false);

	// Testfall 11: Gemischt ungerade ""
	assert(is_correct_syntax("echo \'Hello\' world\" \"how\" are \'you\'") == false);

	// Testfall 12: Gemischt ungerade " und '
	assert(is_correct_syntax("echo \'Hello\' world\" \"how\" are you\'") == false);

	// Testfall 13: Korrektes Escapen eines Anführungszeichens
	assert(is_correct_syntax("echo \"This is \\\"a test\\\" example\"") == true);

	// Testfall 14: Fehlendes schließendes Anführungszeichen nach Escapen
	assert(is_correct_syntax("echo \"This is \\\"a test\\\" example") == false);

	// Testfall 15: Korrekter Umgang mit Leerzeichen und Anführungszeichen
	assert(is_correct_syntax("echo 'Hello,    world!'") == true);

	// Testfall 16: Verschachtelte Anführungszeichen richtig behandelt
	assert(is_correct_syntax("echo 'This is a \"nested quote\" inside'") == true);

	// Testfall 17: Unausgeglichene Verschachtelung
	assert(is_correct_syntax("echo 'This is a \"nested quote inside'") == false);

	// Testfall 18: Korrekte Behandlung von Escapen innerhalb von Anführungszeichen
	assert(is_correct_syntax("echo 'It\\\'s a nice day'") == true);

	// Testfall 19: Mehrere verschachtelte und korrekt geschlossene Anführungszeichen
	assert(is_correct_syntax("echo 'John said, \"She said, \\\'Hello\\\'\"'") == true);

	// Testfall 20: Fehlendes Escapen innerhalb von Anführungszeichen
	assert(is_correct_syntax("echo 'It's a nice day'") == false);

	// Testfall 21: Gültiger Befehl mit komplexen Anführungszeichen
	assert(is_correct_syntax("echo \"This 'is' a 'test' of 'quotes'\"") == true);

	// Testfall 22: Ungerade Anzahl von Anführungszeichen in komplexer Verschachtelung
	assert(is_correct_syntax("echo \"This 'is' a 'test of 'quotes'\"") == false);

	// Testfall 23: Gültige Verwendung von Leerzeichen um Anführungszeichen
	assert(is_correct_syntax("   echo    'Hello   world'   ") == true);

	// Testfall 24: Korrekte Umleitung mit Anführungszeichen
	assert(is_correct_syntax("echo 'Hello' > 'filename.txt'") == true);

	// Testfall 25: Gültiger Befehl mit Backslash
	assert(is_correct_syntax("echo This is a backslash \\\\") == true);

	// Testfall 26: Gemischt korrekt und ungerade Anführungszeichen
	assert(is_correct_syntax("echo 'Hello' \"What's up\" \"world") == false);

	// Testfall 27: Gemischt falsch und ungerade Anführungszeichen
	assert(is_correct_syntax("echo \"Hello'\' What's \"up\' world") == false);

	// Testfall 28:
	// assert(is_correct_syntax() == false);

	printf("Alle Tests in test_is_correct_syntax erfolgreich.\n");
}
