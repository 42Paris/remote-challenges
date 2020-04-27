#include <assert.h>
#include <stdio.h>
#include <string.h>

char *ft_rgb2hex(int r, int g, int b);

void assert_results(int r, int g, int b, char *expected) {
        char *result;
        result = ft_rgb2hex(r, g, b);
        printf("test: ft_rgb2hex(%d, %d, %d)\nexpected_output: '%s' ", r, g, b, expected);
        printf("user_output: '%s'\n", result);
        assert(!strcmp(result, expected));
}

int main() {
        assert_results(252, 186, 3, "#fcba03");
        assert_results(70, 235, 52, "#46eb34");
        assert_results(159, 52, 235, "#9f34eb");
        assert_results(52, 101, 235, "#3465eb");
        assert_results(52, 235, 119, "#34eb77");
        assert_results(208, 235, 52, "#d0eb34");
        assert_results(0, 0, 255, "#0000ff");
        assert_results(0, 255, 0, "#00ff00");
        assert_results(255, 0, 0, "#ff0000");
        assert_results(255, 255, 255, "#ffffff");
}
