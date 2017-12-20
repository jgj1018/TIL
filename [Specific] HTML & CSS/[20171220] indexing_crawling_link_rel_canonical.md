[ref1](https://webmasters.googleblog.com/2009/02/specify-your-canonical.html)
[ref2](https://webmasters.googleblog.com/2011/09/pagination-with-relnext-and-relprev.html)
[ref3](https://bazubu.com/seo101/how-to-use-prev-and-next)

# Specify my canonical

If my site has identical or vastly similar content that's accessible through multiple URLs, this format provides I with more control over the URL returned in search results. It also helps to make sure that properties such as link popularity are consolidated to my preferred version.

I can simply add this <link> tag to specify my preferred version:

```
<link rel="canonical" href="http://www.example.com/product.php?item=swedish-fish" />
```

inside the <head> section of the duplicate content URLs:

```
http://www.example.com/product.php?item=swedish-fish&category=gummy-candy
http://www.example.com/product.php?item=swedish-fish&trackingid=1234&sessionid=5678
```

and Google will understand that the duplicates all refer to the canonical URL: http://www.example.com/product.php?item=swedish-fish. Additional URL properties, like PageRank and related signals, are transferred as well.

This standard can be adopted by any search engine when crawling and indexing my site.

# Pagination with rel=“next” and rel=“prev”

Much like rel=”canonical” acts a strong hint for duplicate content, I can now use the HTML link elements rel=”next” and rel=”prev” to indicate the relationship between component URLs in a paginated series. Throughout the web, a paginated series of content may take many shapes—it can be an article divided into several component pages, or a product category with items spread across several pages, or a forum thread divided into a sequence of URLs. Now, if I choose to include rel=”next” and rel=”prev” markup on the component pages within a series, I am giving Google a strong hint that I’d like us to:

- Consolidate indexing properties, such as links, from the component pages/URLs to the series as a whole (i.e., links should not remain dispersed between page-1.html, page-2.html, etc., but be grouped with the sequence).
- Send users to the most relevant page/URL—typically the first page of the series.

# Implementing rel=”next” and rel=”prev”

If I prefer option 3 (above) for my site, let’s get started! Let’s say I have content paginated into the URLs:

```
http://www.example.com/article?story=abc&page=1
http://www.example.com/article?story=abc&page=2
http://www.example.com/article?story=abc&page=3
http://www.example.com/article?story=abc&page=4
```

On the first page, http://www.example.com/article?story=abc&page=1, I’d include in the <head> section:
```
<link rel="next" href="http://www.example.com/article?story=abc&page=2" />
```
On the second page, http://www.example.com/article?story=abc&page=2:
```
<link rel="prev" href="http://www.example.com/article?story=abc&page=1" />
<link rel="next" href="http://www.example.com/article?story=abc&page=3" />
```
On the third page, http://www.example.com/article?story=abc&page=3:
```
<link rel="prev" href="http://www.example.com/article?story=abc&page=2" />
<link rel="next" href="http://www.example.com/article?story=abc&page=4" />
```
And on the last page, http://www.example.com/article?story=abc&page=4:
```
<link rel="prev" href="http://www.example.com/article?story=abc&page=3" />
```

A few points to mention:
- The first page only contains rel=”next” and no rel=”prev” markup.
- Pages two to the second-to-last page should be doubly-linked with both rel=”next” and rel=”prev” markup.
- The last page only contains markup for rel=”prev”, not rel=”next”.

- rel=”next” and rel=”prev” values can be either relative or absolute URLs (as allowed by the <link> tag). And, if I include a <base> link in my document, relative paths will resolve according to the base URL.
- rel=”next” and rel=”prev” only need to be declared within the <head> section, not within the document <body>.
- rel="next" and rel="previous" on the one hand and rel="canonical" on the other constitute independent concepts. Both declarations can be included in the same page
- 
```
<link rel="canonical" href="http://www.example.com/article?story=abc&page=2”/>
<link rel="prev" href="http://www.example.com/article?story=abc&page=1&sessionid=123" />
<link rel="next" href="http://www.example.com/article?story=abc&page=3&sessionid=123" />
```