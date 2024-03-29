-------------------------------------------------------------------------------
-- main.lua
-- by Stewart Bracken  http://stewart.bracken.bz  stew.bracken@gmail.com
-- Sample Corona app that uses TwilioRestClient
-- Please ignore bugs as this app was not intended to be published.
-------------------------------------------------------------------------------
local mob = require("mobdebug")
if mob then mob.start() end
local TwilioRestClient = require "Twilio.TwilioRestClient"
local auth = require "tests.auth" or {}
--Plug in your twilio account credentials here in the XXXX's
ACCOUNT_SID = auth.ACCOUNT_SID or "XXXXXXXX" -- your Account SID
ACCOUNT_TOKEN = auth.ACCOUNT_TOKEN or "XXXXXX" --your account token
--Outgoing Caller phone number
CALLER_TO = auth.CALLER_TO or "+1NNNNNNNNNN"
--Incoming Caller Phone Number, previously validated with Twilio
CALLER_FROM = auth.CALLER_FROM or "+1NNNNNNNNNN"

--Lets just make our TwilioRestClient global because it's easier to use across scenes
R = TwilioRestClient.create(ACCOUNT_SID, ACCOUNT_TOKEN)
--Build example GUI
-- Hide the status bar
display.setStatusBar( display.HiddenStatusBar )

--Set background to white
display.setDefault( "background", 255, 255, 255 )

-- Require the widget & storyboard libraries
local widget = require( "widget" )
local storyboard = require( "storyboard" )

-- The gradient used by the title bar
local titleGradient = graphics.newGradient( 
	{ 189, 203, 220, 255 }, 
	{ 89, 116, 152, 255 }, "down" )

-- Create a title bar
local titleBar = display.newRect( 0, 0, display.contentWidth, 32 )
titleBar.y = titleBar.contentHeight * 0.5
titleBar:setFillColor( titleGradient )	

-- Create the title bar text
local titleBarText = display.newText( "Twilio + Corona by Stewart Bracken", 0, 0, native.systemFontBold, 16 )
titleBarText.x = titleBar.x
titleBarText.y = titleBar.y

-- Start at calltab
storyboard.gotoScene( "calltab" )

local sceneTransitionOptions = { effect='slideLeft', time="300", }
local tabButtons = 
{
    {
        width = 32, 
        height = 32,
        defaultFile = "assets/tabIcon.png",
        overFile = "assets/tabIcon-down.png",
        label = "Make a call!",
        onPress = function() storyboard.gotoScene( "calltab",sceneTransitionOptions ); end,
        selected = true
    },
    {
        width = 32, 
        height = 32,
        defaultFile = "assets/tabIcon.png",
        overFile = "assets/tabIcon-down.png",
        label = "Send SMS",
        onPress = function() storyboard.gotoScene( "sendsms",sceneTransitionOptions ); end,
    },
    {
        width = 32, 
        height = 32,
        defaultFile = "assets/tabIcon.png",
        overFile = "assets/tabIcon-down.png",
        label = "Call logs",
        onPress = function() storyboard.gotoScene( "calllog",sceneTransitionOptions ); end,
    }
}

-- Create a tab-bar and place it at the bottom of the screen
local tabBar = widget.newTabBar
{
    top = display.contentHeight - 50,
    width = display.contentWidth,
    buttons = tabButtons
}