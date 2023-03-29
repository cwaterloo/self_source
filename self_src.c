#include <stdio.h>
#include <string.h>

void escape(const char *in, char* out) {
  int j = 0;
  for (int i = 0; in[i]; i++) {
    switch (in[i]) {
      case 34:
        out[j++] = 92;
        out[j++] = 34;
        break;
      case 92:
        out[j++] = 92;
        out[j++] = 92;
        break;
      default:
        out[j++] = in[i];
        break;
    }
  }
  out[j] = 0;
}

const char kBody[][80] = {
  "#include <stdio.h>",
  "#include <string.h>",
  "",
  "void escape(const char *in, char* out) {",
  "  int j = 0;",
  "  for (int i = 0; in[i]; i++) {",
  "    switch (in[i]) {",
  "      case 34:",
  "        out[j++] = 92;",
  "        out[j++] = 34;",
  "        break;",
  "      case 92:",
  "        out[j++] = 92;",
  "        out[j++] = 92;",
  "        break;",
  "      default:",
  "        out[j++] = in[i];",
  "        break;",
  "    }",
  "  }",
  "  out[j] = 0;",
  "}",
  "",
  "const char kBody[][80] = {",
  "};",
  "",
  "int main() {",
  "  char buffer[160];",
  "  for (int i = 0; i < 24; i++) {",
  "    puts(kBody[i]);",
  "  }",
  "  for (int i = 0; i < 40; i++) {",
  "    escape(kBody[i], buffer);",
  "    printf(\"  \\\"%s\\\",\\n\", buffer);",
  "  }",
  "  for (int i = 24; i < 40; i++) {",
  "    puts(kBody[i]);",
  "  }",
  "  return 0;",
  "}",
};

int main() {
  char buffer[160];
  for (int i = 0; i < 24; i++) {
    puts(kBody[i]);
  }
  for (int i = 0; i < 40; i++) {
    escape(kBody[i], buffer);
    printf("  \"%s\",\n", buffer);
  }
  for (int i = 24; i < 40; i++) {
    puts(kBody[i]);
  }
  return 0;
}
