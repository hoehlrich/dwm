/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 12;       /* 2 is the default spacing around the bar's font */
static const char *fonts[]          = { "monospace:size=12", "FiraCodeNerdFontMono-Regular:size=20" };
static const char dmenufont[]       = "monospace:size=12";


static const char red[]      = "#cc241d";
static const char green[]    = "#98971a";
static const char yellow[]   = "#d79921";
static const char blue[]     = "#458588";
static const char purple[]   = "#b16286";
static const char aqua[]     = "#689d61";
static const char orange[]   = "#d65d0e";
static const char gray[]     = "#928374";
static const char l_red[]    = "#fb4934";
static const char l_green[]  = "#b8bb26";
static const char l_yellow[] = "#fabd2f";
static const char l_blue[]   = "#83a598";
static const char l_purple[] = "#d3869b";
static const char l_aqua[]   = "#8ec07c";
static const char l_orange[] = "#fe8019";
static const char l_gray[]   = "#a89984";
static const char bg[]       = "#282828";
static const char fg[]       = "#ebdbb2";
static const char bg0_h[]    = "#1d2021";
static const char bg0_s[]    = "#32302f";
static const char bg0[]      = "#282828";
static const char bg1[]      = "#3c3836";
static const char bg2[]      = "#504945";
static const char bg3[]      = "#665c54";
static const char bg4[]      = "#7c6f64";
static const char fg0[]      = "#fbf1c7";
static const char fg1[]      = "#ebdbb2";
static const char fg2[]      = "#d5c4a1";
static const char fg3[]      = "#bdae93";
static const char fg4[]      = "#a89984";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { fg, bg1, bg2 },
	[SchemeSel]  = { fg2, bg1, fg2 },
};

/* tagging */
static const char *tags[] = { "  ", "  ", " 󰈙 ", "  ", "  ", "  ", "  ", "  ", "  " };

static const unsigned int ulinepad	   = 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset = 3;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		       = 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

#define TERMINAL "st"

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-h", "30", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *editorcmd[] = { "st", "nvim", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *spotifycmd[] = { "st", "spt", NULL };
static const char *fbcmd[] = { "st", "ranger", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_v,      spawn,          {.v = editorcmd } },
	{ MODKEY,                       XK_s,      spawn,          {.v = spotifycmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = fbcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_m,      spawn,          SHCMD("pamixer -t") },
	{ MODKEY,                       XK_minus,  spawn,          SHCMD("pamixer -d 5") },
	{ MODKEY,                       XK_equal,  spawn,          SHCMD("pamixer -i 5") },
	{ MODKEY|ShiftMask,             XK_equal,  spawn,          SHCMD("mpc volume +10") },
	{ MODKEY|ShiftMask,             XK_minus,  spawn,          SHCMD("mpc volume -10") },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          SHCMD("mpc next") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("mpc prev") },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("mpc toggle") },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("mpc clear") },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("mpc shuffle") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

