#pragma once

class rgbaVector {
private:
	float r;
	float g;
	float b;
	float a;
public:
	void setRGBA(float x, float y, float z, float w) {
		r = x;
		g = y;
		b = z;
		a = w;
	}
	float getR() {
		return r;
	}
	float getG() {
		return g;
	}
	float getB() {
		return b;
	}
	float getA() {
		return a;
	}
};

class Color : public rgbaVector {
	public:
		Color(float x, float y, float z, float w);
};
Color::Color(float x, float y, float z, float w) {
	setRGBA(x, y, z, w);
}

class Colors {
	public:
		rgbaVector lightYellow();
		rgbaVector babyBlue();
		rgbaVector lilac();
		rgbaVector greenApple();
		rgbaVector orange();
};

rgbaVector Colors::lightYellow() {
	return Color(220.0f, 20.0f, 0.60f, 1.0f);
}

rgbaVector Colors::babyBlue() {
	return Color(0.80f, 160.0f, 255.0f, 1.0f);
}

rgbaVector Colors::lilac() {
	return Color(200.0f, 0.80f, 150.0f, 1.0f);
}

rgbaVector Colors::greenApple() {
	return Color(0.80f, 200.0f, 0.0f, 1.0f);
}

rgbaVector Colors::orange() {
	return Color(200.0f, 0.80f, 0.0f, 1.0f);
}
