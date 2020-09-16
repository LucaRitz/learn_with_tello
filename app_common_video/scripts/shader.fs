# version 330 core

out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;

uniform sampler2D texture1;

void main() {
	float ambientFactor = 0.2;
	vec3 ambientLight = ambientFactor * vec3(1.0, 1.0, 1.0);
	FragColor = vec4(ambientLight, 1.0) * texture(texture1, TexCoord);
}