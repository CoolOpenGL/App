#pragma once

namespace Cool {

class IApp {
public:
	IApp() = default;
	~IApp() = default;

	/// <summary>
	/// Update function that will be called repeatedly
	/// </summary>
	virtual void update() {};

	/// <summary>
	/// Please create all your ImGui windows inside this function (allows the AppManager to hide all UI when the user presses CTRL+H, and the dockspace to apply properly)
	/// </summary>
	virtual void ImGuiWindows() {};

	/// <summary>
	/// Put all menus that should appear on the top menu bar here.
	/// </summary>
	virtual void ImGuiMenus() {};

	/// <summary>
	/// This is where you receive and handle keyboard events.
	/// For full informations, check out GLFW's documentation for glfwSetKeyCallback : https://www.glfw.org/docs/latest/group__input.html#ga1caf18159767e761185e49a3be019f8d
	/// </summary>
	/// <param name="key">The physical key (independant of a QWERTY vs AZERTY layout). Something like GLFW_KEY_A, GLFW_KEY_B etc.
	/// It might be GLFW_KEY_UNKNOWN if GLFW lacks a key token for it, for example for E-mail and Play keys.
	/// If you want to check for a character according to the keyboard layout, use Input::MatchesChar()</param>
	/// <param name="scancode">The scancode is unique for every key, regardless of whether it has a key token. Scancodes are platform-specific but consistent over time, so keys will have different scancodes depending on the platform but they are safe to save to disk. You can query the scancode for any named key on the current platform with glfwGetKeyScancode.</param>
	/// <param name="action">The action is one of GLFW_PRESS, GLFW_REPEAT or GLFW_RELEASE</param>
	/// <param name="mods">Flags indicating whether modifier keys are being pressed at the same time.
	/// For example call (mods &amp; GLFW_MOD_SHIFT) to check if SHIFT is pressed</param>
	virtual void onKeyboardEvent(int key, int scancode, int action, int mods) {};

	/// <summary>
	/// This is where you receive and handle mouse button events.
	/// </summary>
	/// <param name="button">Can be GLFW_MOUSE_BUTTON_LEFT, GLFW_MOUSE_BUTTON_RIGHT, GLFW_MOUSE_BUTTON_MIDDLE and some more that you can check at https://www.glfw.org/docs/latest/group__buttons.html</param>
	/// <param name="action">Can be GLFW_PRESS or GLFW_RELEASE</param>
	/// <param name="mods">Flags indicating whether modifier keys are being pressed at the same time.
	/// For example call (mods &amp; GLFW_MOD_SHIFT) to check if SHIFT is pressed</param>
	virtual void onMouseButtonEvent(int button, int action, int mods) {};

	/// <summary>
	/// This is where you receive and handle mouse scroll events (which can also be generated by a touch pad).
	/// </summary>
	/// <param name="xOffset">Delta in the x direction</param>
	/// <param name="yOffset">Delta in the y direction. This is what most mouses and touch pads will generate</param>
	virtual void onScrollEvent(double xOffset, double yOffset) {};

	/// <summary>
	/// This is where you receive and handle mouse move events.
	/// </summary>
	/// <param name="xpos">Current x position of the mouse, in pixels, relative to the top-left of the window.</param>
	/// <param name="ypos">Current y position of the mouse, in pixels, relative to the top-left of the window.</param>
	virtual void onMouseMoveEvent(double xPos, double yPos) {};
};

} // namespace Cool