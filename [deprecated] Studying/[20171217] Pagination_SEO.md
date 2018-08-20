[REF1](https://moz.com/blog/pagination-best-practices-for-seo-user-experience) 
[REF2](http://www.digitalvidya.com/blog/pagination-tips-for-seo/)


# Why is Pagination an SEO Issue?

Pagination, the practice of segmenting links to content on multiple pages, affects two critical elements of search engine accessibility.

- Crawl Depth: Best practices demand that the search engine spiders reach content-rich pages in as few "clicks" as possible
- Duplicate Content: Search engines take duplication very seriously and attempt to show only a single URL that contains any given piece of content. 
max_num

# Numbers of Links & Pages

- Try to link to as many pages of the pagination structure as possible without breaking the 100(ish) links per page limit
- Show newer content at the top of the results list when possible, as this means the most link juice will flow to newer articles that need it (and are temporally relevant)
- Use and link to relevant/related categories & subcategories to help keep link juice flowing throughout the site
- Link back to the top results from each of the paginated URLs

# Nofollows. Rel=Canonicals and Conditional Redirects

- Put a rel=canonical directive on paginated results pointing back to the top page in an attempt to flow link juice to that URL. I'll either misdirect the engines into thinking I have only a single page of results or convince them that my directives aren't worth following (as they find clearly unique content on those pages).
- Add nofollow to the paginated links on the results pages. This tells the engines not to flow link juice/votes/authority down into the results pages that desperately need those votes to help them get indexed and pass value to the deeper pages.
- Create a conditional redirect so that when search engines request paginated results, they 301 redirect or meta refresh back to the top page of results.

The only time I recommend using any of these is when pagination exists in multiple formats. For example, if I let users re-sort by a number of different metrics (in a restaurant list, for example, it might be by star rating, distance, name, price, etc.), I may want to either perform this re-sort using javascript (and employ the hash tag in the URL) or make those separately segmented paginated results rel=canonical back to a single sorting format.

# Classic Pagination for SEO: Using no index

There could be certain sections or pages on my site that I feel are relatively unimportant. It would make no difference if the search engines completely skip over these pages of content.

I can stop the search engines from indexing pages by using the no index tag. I can do this for every page in the paginated series other than the first page.

- Implement a <META NAME=”ROBOTS” CONTENT=”NOINDEX,FOLLOW”> tag within the <head> section on all pages from 2 to n.
- Including the “FOLLOW” tag in a series of pages within a category ensures that page authority travels to the individual pages throughout the list.  The follow tag also helps in transferring some equity from the subsidiary pages in a series to the primary page or the site.