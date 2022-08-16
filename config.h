/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody"; // use "nobody" for arch

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
	#if PAMAUTH_PATCH
	[PAM] =    "#9400D3",   /* waiting for PAM */
	#endif // PAMAUTH_PATCH
	#if KEYPRESS_FEEDBACK_PATCH
	[BLOCKS] = "#ffffff",   /* key feedback block */
	#endif // KEYPRESS_FEEDBACK_PATCH
};

#if XRESOURCES_PATCH
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "locked",       STRING,  &colorname[INIT] },
		{ "input",        STRING,  &colorname[INPUT] },
		{ "failed",       STRING,  &colorname[FAILED] },
		#if CAPSCOLOR_PATCH
		{ "capslock",     STRING,  &colorname[CAPS] },
		#endif // CAPSCOLOR_PATCH
		#if PAMAUTH_PATCH
		{ "pamauth",      STRING,  &colorname[PAM] },
		#endif // PAMAUTH_PATCH
};
#endif // XRESOURCES_PATCH

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

#if FAILURE_COMMAND_PATCH
/* number of failed password attempts until failcommand is executed.
   Set to 0 to disable */
static const int failcount = 5;

/* command to be executed after [failcount] failed password attempts */
static const char *failcommand = "shutdown now";
#endif // FAILURE_COMMAND_PATCH

#if SECRET_PASSWORD_PATCH
static const secretpass scom[] = {
	/* Password             command */
	{ "sn",           "shutdown now"},
};
#endif // SECRET_PASSWORD_PATCH

#if BLUR_PIXELATED_SCREEN_PATCH
/* Enable blur */
#define BLUR
/* Set blur radius */
static const int blurRadius = 10;
/* Enable Pixelation */
// #define PIXELATION
/* Set pixelation radius */
static const int pixelSize = 10;
#endif // BLUR_PIXELATED_SCREEN_PATCH

#if CONTROLCLEAR_PATCH
/* allow control key to trigger fail on clear */
static const int controlkeyclear = 0;
#endif // CONTROLCLEAR_PATCH

#if KEYPRESS_FEEDBACK_PATCH
static short int blocks_enabled = 1; // 0 = don't show blocks
static const int blocks_width = 0; // 0 = full width
static const int blocks_height = 16;

// position
static const int blocks_x = 0;
static const int blocks_y = 0;

// Number of blocks
static const int blocks_count = 5;
#endif // KEYPRESS_FEEDBACK_PATCH

#if PAMAUTH_PATCH
/* PAM service that's used for authentication */
static const char* pam_service = "login";
#endif // PAMAUTH_PATCH

#if QUICKCANCEL_PATCH
/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 4;
#endif // QUICKCANCEL_PATCH
