$(document).ready(function()
{
    // Disqus integration.
    if ( window.location.protocol === 'http:' )
    {
        $('#content').append('<div id="disqus_thread"></div>');
        var disqus_shortname = 'sincebelieve';
        var dsq = document.createElement('script');
        dsq.type = 'text/javascript';
        dsq.async = true;
        dsq.src = '//' + disqus_shortname + '.disqus.com/embed.js';
        (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
    }

    // Blackboard style background.
    $('<div id="content-top">').prependTo('#content');
    $('<div id="content-bottom">').appendTo('#content');

    // Corners of Image display.
    $('div.figure').after('<div class="figure-clear" />');
    $('<div class="figure-corner-north figure-corner-west">').prependTo('div.figure');
    $('<div class="figure-corner-north figure-corner-east">').prependTo('div.figure');
    $('<div class="figure-corner-south figure-corner-west">').prependTo('div.figure');
    $('div.figure').wrap('<div class="figure-container"></div>');

    $('head').append('<link href="https://fonts.googleapis.com/css?family=Handlee" rel="stylesheet">');
});
