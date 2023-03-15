--
-- PostgreSQL database dump
--

-- Dumped from database version 15.1
-- Dumped by pg_dump version 15.1

-- Started on 2022-12-26 16:55:42

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 240 (class 1255 OID 17493)
-- Name: add_library_func(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.add_library_func() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
begin
	Insert into library values (default, new.id, default);
	return new;
end;
$$;


ALTER FUNCTION public.add_library_func() OWNER TO postgres;

--
-- TOC entry 244 (class 1255 OID 17530)
-- Name: add_song(integer, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.add_song(IN p1 integer, IN p2 integer)
    LANGUAGE plpgsql
    AS $$
begin

insert into playlist_song values (p1, p2);

end; $$;


ALTER PROCEDURE public.add_song(IN p1 integer, IN p2 integer) OWNER TO postgres;

--
-- TOC entry 261 (class 1255 OID 17540)
-- Name: change_playlist_name(text, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.change_playlist_name(IN p1 text, IN p2 integer)
    LANGUAGE plpgsql
    AS $$
begin

update playlist set name = p1 where id = p2;

end; $$;


ALTER PROCEDURE public.change_playlist_name(IN p1 text, IN p2 integer) OWNER TO postgres;

--
-- TOC entry 242 (class 1255 OID 17521)
-- Name: decrease_song_amount_func(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.decrease_song_amount_func() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
begin
	update playlist set song_amount = song_amount - 1 where id = old.playlist_id;
	return new;
end;
$$;


ALTER FUNCTION public.decrease_song_amount_func() OWNER TO postgres;

--
-- TOC entry 245 (class 1255 OID 17531)
-- Name: delete_song(integer, integer); Type: PROCEDURE; Schema: public; Owner: postgres
--

CREATE PROCEDURE public.delete_song(IN p1 integer, IN p2 integer)
    LANGUAGE plpgsql
    AS $$
begin

delete from playlist_song where playlist_id = p1 and song_id = p2;

end; $$;


ALTER PROCEDURE public.delete_song(IN p1 integer, IN p2 integer) OWNER TO postgres;

--
-- TOC entry 260 (class 1255 OID 17539)
-- Name: find_song(text); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.find_song(p1 text) RETURNS TABLE(songid integer, songname character varying, artist character varying, album character varying)
    LANGUAGE plpgsql
    AS $$
begin
	return query
	select song.id, song.name, artist.name, album.name from album_song
	inner join album
	on album_song.album_id = album.id
	inner join song
	on album_song.song_id = song.id 
	inner join artist
	on album.artist = artist.id
	where song.name = p1;
end;
$$;


ALTER FUNCTION public.find_song(p1 text) OWNER TO postgres;

--
-- TOC entry 252 (class 1255 OID 17536)
-- Name: find_song(character varying); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.find_song(p1 character varying) RETURNS TABLE(songid integer, songname character varying, artist character varying, album character varying)
    LANGUAGE plpgsql
    AS $$
begin
	return query
	select song.id, song.name, artist.name, album.name from album_song
	inner join album
	on album_song.album_id = album.id
	inner join song
	on album_song.song_id = song.id 
	inner join artist
	on album.artist = artist.id
	where song.name = p1;
end;
$$;


ALTER FUNCTION public.find_song(p1 character varying) OWNER TO postgres;

--
-- TOC entry 243 (class 1255 OID 17523)
-- Name: increase_playlist_amount_func(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.increase_playlist_amount_func() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
begin
	update library set playlist_amount = playlist_amount + 1 where id = new.library_id;
	return new;
end;
$$;


ALTER FUNCTION public.increase_playlist_amount_func() OWNER TO postgres;

--
-- TOC entry 241 (class 1255 OID 17519)
-- Name: increase_song_amount_func(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.increase_song_amount_func() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
begin
	update playlist set song_amount = song_amount + 1 where id = new.playlist_id;
	return new;
end;
$$;


ALTER FUNCTION public.increase_song_amount_func() OWNER TO postgres;

--
-- TOC entry 246 (class 1255 OID 17532)
-- Name: playlist_list(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.playlist_list() RETURNS TABLE(playlistid integer, playlistadi character varying, sarkiid integer, sarkiadi character varying)
    LANGUAGE plpgsql
    AS $$
begin
	return query
	select playlist.id, playlist.name, song.id, song.name from playlist_song
	inner join playlist
	on playlist_song.playlist_id = playlist.id
	inner join song
	on playlist_song.song_id = song.id ORDER BY playlist_id ASC, song_id ASC;
end;
$$;


ALTER FUNCTION public.playlist_list() OWNER TO postgres;

--
-- TOC entry 247 (class 1255 OID 17533)
-- Name: song_list(); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.song_list() RETURNS TABLE(songid integer, songname character varying, artist character varying, album character varying)
    LANGUAGE plpgsql
    AS $$
begin
	return query
	select song.id, song.name, artist.name, album.name from album_song
	inner join album
	on album_song.album_id = album.id
	inner join song
	on album_song.song_id = song.id 
	inner join artist
	on album.artist = artist.id
	ORDER BY album_id ASC, song_id ASC;
end;
$$;


ALTER FUNCTION public.song_list() OWNER TO postgres;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 223 (class 1259 OID 17247)
-- Name: album; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.album (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    artist integer NOT NULL,
    created_at date DEFAULT CURRENT_DATE NOT NULL,
    song_amount integer DEFAULT 0
);


ALTER TABLE public.album OWNER TO postgres;

--
-- TOC entry 222 (class 1259 OID 17246)
-- Name: album_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.album_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.album_id_seq OWNER TO postgres;

--
-- TOC entry 3513 (class 0 OID 0)
-- Dependencies: 222
-- Name: album_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.album_id_seq OWNED BY public.album.id;


--
-- TOC entry 233 (class 1259 OID 17351)
-- Name: album_song; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.album_song (
    album_id integer NOT NULL,
    song_id integer NOT NULL
);


ALTER TABLE public.album_song OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 17170)
-- Name: profile; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.profile (
    id integer NOT NULL,
    username character varying(100) NOT NULL,
    email character varying(50) NOT NULL,
    password integer NOT NULL,
    created_at date DEFAULT CURRENT_DATE
);


ALTER TABLE public.profile OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 17183)
-- Name: artist; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.artist (
    name character varying(100) NOT NULL
)
INHERITS (public.profile);


ALTER TABLE public.artist OWNER TO postgres;

--
-- TOC entry 237 (class 1259 OID 17412)
-- Name: artist_followers; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.artist_followers (
    artist_id integer NOT NULL,
    follower_id integer NOT NULL
);


ALTER TABLE public.artist_followers OWNER TO postgres;

--
-- TOC entry 225 (class 1259 OID 17279)
-- Name: episode; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.episode (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    category integer NOT NULL
);


ALTER TABLE public.episode OWNER TO postgres;

--
-- TOC entry 227 (class 1259 OID 17288)
-- Name: episode_category; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.episode_category (
    id integer NOT NULL,
    name character varying(50) NOT NULL
);


ALTER TABLE public.episode_category OWNER TO postgres;

--
-- TOC entry 226 (class 1259 OID 17287)
-- Name: episode_category_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.episode_category_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.episode_category_id_seq OWNER TO postgres;

--
-- TOC entry 3514 (class 0 OID 0)
-- Dependencies: 226
-- Name: episode_category_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.episode_category_id_seq OWNED BY public.episode_category.id;


--
-- TOC entry 224 (class 1259 OID 17278)
-- Name: episode_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.episode_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.episode_id_seq OWNER TO postgres;

--
-- TOC entry 3515 (class 0 OID 0)
-- Dependencies: 224
-- Name: episode_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.episode_id_seq OWNED BY public.episode.id;


--
-- TOC entry 238 (class 1259 OID 17427)
-- Name: follows; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.follows (
    follower_id integer NOT NULL,
    followed_id integer NOT NULL
);


ALTER TABLE public.follows OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 17218)
-- Name: library; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.library (
    id integer NOT NULL,
    listener_id integer DEFAULT 0 NOT NULL,
    playlist_amount integer DEFAULT 0 NOT NULL
);


ALTER TABLE public.library OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 17217)
-- Name: library_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.library_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.library_id_seq OWNER TO postgres;

--
-- TOC entry 3516 (class 0 OID 0)
-- Dependencies: 218
-- Name: library_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.library_id_seq OWNED BY public.library.id;


--
-- TOC entry 236 (class 1259 OID 17397)
-- Name: library_playlist; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.library_playlist (
    library_id integer NOT NULL,
    playlist_id integer NOT NULL
);


ALTER TABLE public.library_playlist OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 17205)
-- Name: listener; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.listener (
    name character varying(100) NOT NULL,
    listened_song_amount integer DEFAULT 0 NOT NULL
)
INHERITS (public.profile);


ALTER TABLE public.listener OWNER TO postgres;

--
-- TOC entry 235 (class 1259 OID 17382)
-- Name: playlist; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.playlist (
    id integer NOT NULL,
    name character varying NOT NULL,
    created_at date DEFAULT CURRENT_DATE NOT NULL,
    creater integer NOT NULL,
    song_amount integer DEFAULT 0 NOT NULL
);


ALTER TABLE public.playlist OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 17381)
-- Name: playlist_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.playlist_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.playlist_id_seq OWNER TO postgres;

--
-- TOC entry 3517 (class 0 OID 0)
-- Dependencies: 234
-- Name: playlist_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.playlist_id_seq OWNED BY public.playlist.id;


--
-- TOC entry 239 (class 1259 OID 17458)
-- Name: playlist_song; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.playlist_song (
    playlist_id integer NOT NULL,
    song_id integer NOT NULL
);


ALTER TABLE public.playlist_song OWNER TO postgres;

--
-- TOC entry 221 (class 1259 OID 17231)
-- Name: podcast; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.podcast (
    id integer NOT NULL,
    name character varying(50) NOT NULL,
    artist integer NOT NULL,
    created_at date DEFAULT CURRENT_DATE NOT NULL,
    episode_amount integer DEFAULT 0
);


ALTER TABLE public.podcast OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 17296)
-- Name: podcast_episode; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.podcast_episode (
    podcast_id integer NOT NULL,
    episode_id integer NOT NULL
);


ALTER TABLE public.podcast_episode OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 17230)
-- Name: podcast_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.podcast_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.podcast_id_seq OWNER TO postgres;

--
-- TOC entry 3518 (class 0 OID 0)
-- Dependencies: 220
-- Name: podcast_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.podcast_id_seq OWNED BY public.podcast.id;


--
-- TOC entry 214 (class 1259 OID 17169)
-- Name: profile_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.profile_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.profile_id_seq OWNER TO postgres;

--
-- TOC entry 3519 (class 0 OID 0)
-- Dependencies: 214
-- Name: profile_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.profile_id_seq OWNED BY public.profile.id;


--
-- TOC entry 229 (class 1259 OID 17311)
-- Name: song_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.song_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.song_id_seq OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 17312)
-- Name: song; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.song (
    id integer DEFAULT nextval('public.song_id_seq'::regclass) NOT NULL,
    name character varying(50) NOT NULL,
    category integer NOT NULL
);


ALTER TABLE public.song OWNER TO postgres;

--
-- TOC entry 232 (class 1259 OID 17340)
-- Name: song_category; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.song_category (
    id integer NOT NULL,
    name character varying(50) NOT NULL
);


ALTER TABLE public.song_category OWNER TO postgres;

--
-- TOC entry 231 (class 1259 OID 17339)
-- Name: song_category_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.song_category_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.song_category_id_seq OWNER TO postgres;

--
-- TOC entry 3520 (class 0 OID 0)
-- Dependencies: 231
-- Name: song_category_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.song_category_id_seq OWNED BY public.song_category.id;


--
-- TOC entry 3269 (class 2604 OID 17250)
-- Name: album id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.album ALTER COLUMN id SET DEFAULT nextval('public.album_id_seq'::regclass);


--
-- TOC entry 3258 (class 2604 OID 17186)
-- Name: artist id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist ALTER COLUMN id SET DEFAULT nextval('public.profile_id_seq'::regclass);


--
-- TOC entry 3259 (class 2604 OID 17204)
-- Name: artist created_at; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist ALTER COLUMN created_at SET DEFAULT CURRENT_DATE;


--
-- TOC entry 3272 (class 2604 OID 17282)
-- Name: episode id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.episode ALTER COLUMN id SET DEFAULT nextval('public.episode_id_seq'::regclass);


--
-- TOC entry 3273 (class 2604 OID 17291)
-- Name: episode_category id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.episode_category ALTER COLUMN id SET DEFAULT nextval('public.episode_category_id_seq'::regclass);


--
-- TOC entry 3263 (class 2604 OID 17221)
-- Name: library id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library ALTER COLUMN id SET DEFAULT nextval('public.library_id_seq'::regclass);


--
-- TOC entry 3260 (class 2604 OID 17208)
-- Name: listener id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.listener ALTER COLUMN id SET DEFAULT nextval('public.profile_id_seq'::regclass);


--
-- TOC entry 3261 (class 2604 OID 17209)
-- Name: listener created_at; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.listener ALTER COLUMN created_at SET DEFAULT CURRENT_DATE;


--
-- TOC entry 3276 (class 2604 OID 17385)
-- Name: playlist id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.playlist ALTER COLUMN id SET DEFAULT nextval('public.playlist_id_seq'::regclass);


--
-- TOC entry 3266 (class 2604 OID 17234)
-- Name: podcast id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.podcast ALTER COLUMN id SET DEFAULT nextval('public.podcast_id_seq'::regclass);


--
-- TOC entry 3256 (class 2604 OID 17173)
-- Name: profile id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.profile ALTER COLUMN id SET DEFAULT nextval('public.profile_id_seq'::regclass);


--
-- TOC entry 3275 (class 2604 OID 17343)
-- Name: song_category id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.song_category ALTER COLUMN id SET DEFAULT nextval('public.song_category_id_seq'::regclass);


--
-- TOC entry 3491 (class 0 OID 17247)
-- Dependencies: 223
-- Data for Name: album; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.album (id, name, artist, created_at, song_amount) FROM stdin;
1	Adele Album	2	2022-12-25	4
2	Radiohead Album	3	2022-12-26	4
3	Sebnem Ferah Album	4	2022-12-26	4
4	Mor ve Otesi Album	5	2022-12-26	4
\.


--
-- TOC entry 3501 (class 0 OID 17351)
-- Dependencies: 233
-- Data for Name: album_song; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.album_song (album_id, song_id) FROM stdin;
3	12
3	11
3	10
3	9
2	8
2	7
2	6
2	5
1	4
1	1
4	16
4	15
4	14
4	13
1	3
1	2
\.


--
-- TOC entry 3484 (class 0 OID 17183)
-- Dependencies: 216
-- Data for Name: artist; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.artist (id, username, email, password, created_at, name) FROM stdin;
2	adele	adele@gmail.com	1234	2022-12-25	Adele
3	radiohead	radiohead@gmail.com	1234	2022-12-25	Radiohed
4	sebnemferah	sebnemferah@gmail.com	1234	2022-12-26	Sebnem Ferah
5	morveotesi	morveotesi@gmail.com	1234	2022-12-26	Mor ve Otesi
9	barisozcan	barisozcan@gmail.com	1234	2022-12-26	Baris Ozcan
\.


--
-- TOC entry 3505 (class 0 OID 17412)
-- Dependencies: 237
-- Data for Name: artist_followers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.artist_followers (artist_id, follower_id) FROM stdin;
4	8
3	7
2	1
\.


--
-- TOC entry 3493 (class 0 OID 17279)
-- Dependencies: 225
-- Data for Name: episode; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.episode (id, name, category) FROM stdin;
1	About Drama	3
2	About Life	1
3	About Science	2
4	About Comedy	4
\.


--
-- TOC entry 3495 (class 0 OID 17288)
-- Dependencies: 227
-- Data for Name: episode_category; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.episode_category (id, name) FROM stdin;
1	Life
2	Science
3	Drama
4	Comedy
\.


--
-- TOC entry 3506 (class 0 OID 17427)
-- Dependencies: 238
-- Data for Name: follows; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.follows (follower_id, followed_id) FROM stdin;
8	7
1	7
7	8
\.


--
-- TOC entry 3487 (class 0 OID 17218)
-- Dependencies: 219
-- Data for Name: library; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.library (id, listener_id, playlist_amount) FROM stdin;
1	1	3
2	7	2
3	8	1
\.


--
-- TOC entry 3504 (class 0 OID 17397)
-- Dependencies: 236
-- Data for Name: library_playlist; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.library_playlist (library_id, playlist_id) FROM stdin;
1	3
1	2
3	4
2	3
2	2
1	4
\.


--
-- TOC entry 3485 (class 0 OID 17205)
-- Dependencies: 217
-- Data for Name: listener; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.listener (id, username, email, password, created_at, name, listened_song_amount) FROM stdin;
1	dinleyici	dinleyici@gmail.com	1234	2022-12-25	Dinleyici	0
7	dinleyici2	dinleyici2gmail.com	1234	2022-12-26	Dinleyici2	0
8	dinleyici3	dinleyici3@gmail.com	1234	2022-12-26	Dinleyici3	0
\.


--
-- TOC entry 3503 (class 0 OID 17382)
-- Dependencies: 235
-- Data for Name: playlist; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.playlist (id, name, created_at, creater, song_amount) FROM stdin;
2	Dinleyici1 Calma Listesi	2022-12-25	1	6
4	Dinleyici2 Calma Listesi	2022-12-26	7	6
5	Dinleyici3 Calma Listesi	2022-12-26	8	7
3	Dinleyici2 1. Liste	2022-12-25	1	4
\.


--
-- TOC entry 3507 (class 0 OID 17458)
-- Dependencies: 239
-- Data for Name: playlist_song; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.playlist_song (playlist_id, song_id) FROM stdin;
3	10
3	11
3	7
2	5
2	3
2	8
2	7
2	2
5	11
2	6
4	15
4	10
4	9
4	1
4	4
4	5
5	4
5	6
5	5
5	12
5	13
5	16
3	13
\.


--
-- TOC entry 3489 (class 0 OID 17231)
-- Dependencies: 221
-- Data for Name: podcast; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.podcast (id, name, artist, created_at, episode_amount) FROM stdin;
1	Cagatay's Podcast	2	2022-12-25	4
\.


--
-- TOC entry 3496 (class 0 OID 17296)
-- Dependencies: 228
-- Data for Name: podcast_episode; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.podcast_episode (podcast_id, episode_id) FROM stdin;
1	4
1	3
1	2
1	1
\.


--
-- TOC entry 3483 (class 0 OID 17170)
-- Dependencies: 215
-- Data for Name: profile; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.profile (id, username, email, password, created_at) FROM stdin;
\.


--
-- TOC entry 3498 (class 0 OID 17312)
-- Dependencies: 230
-- Data for Name: song; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.song (id, name, category) FROM stdin;
1	Hometown Glory	1
2	Chasing Pavements	2
3	Million Years Ago	3
4	Rumour Has It	4
5	Jigsaw Falling Into Space	1
6	There, There	2
7	You And Whose Army?	3
8	Fade Out	4
9	Iyi Kotu	1
10	Eski	2
11	Istiklal Caddesi Kadar	3
12	Gozlerimin Etrafindaki Cizgiler	4
13	Son Deneme	1
14	Uyan	2
15	Gunesi Beklerken	3
16	Yagmur, Tesekkurler	4
\.


--
-- TOC entry 3500 (class 0 OID 17340)
-- Dependencies: 232
-- Data for Name: song_category; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.song_category (id, name) FROM stdin;
1	Indie
2	Blues
3	Jazz
4	Rock
\.


--
-- TOC entry 3521 (class 0 OID 0)
-- Dependencies: 222
-- Name: album_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.album_id_seq', 3, true);


--
-- TOC entry 3522 (class 0 OID 0)
-- Dependencies: 226
-- Name: episode_category_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.episode_category_id_seq', 4, true);


--
-- TOC entry 3523 (class 0 OID 0)
-- Dependencies: 224
-- Name: episode_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.episode_id_seq', 4, true);


--
-- TOC entry 3524 (class 0 OID 0)
-- Dependencies: 218
-- Name: library_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.library_id_seq', 4, true);


--
-- TOC entry 3525 (class 0 OID 0)
-- Dependencies: 234
-- Name: playlist_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.playlist_id_seq', 5, true);


--
-- TOC entry 3526 (class 0 OID 0)
-- Dependencies: 220
-- Name: podcast_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.podcast_id_seq', 1, true);


--
-- TOC entry 3527 (class 0 OID 0)
-- Dependencies: 214
-- Name: profile_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.profile_id_seq', 9, true);


--
-- TOC entry 3528 (class 0 OID 0)
-- Dependencies: 231
-- Name: song_category_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.song_category_id_seq', 4, true);


--
-- TOC entry 3529 (class 0 OID 0)
-- Dependencies: 229
-- Name: song_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.song_id_seq', 16, true);


--
-- TOC entry 3296 (class 2606 OID 17256)
-- Name: album pk_album; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.album
    ADD CONSTRAINT pk_album PRIMARY KEY (id);


--
-- TOC entry 3308 (class 2606 OID 17355)
-- Name: album_song pk_album_song; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.album_song
    ADD CONSTRAINT pk_album_song PRIMARY KEY (album_id, song_id);


--
-- TOC entry 3284 (class 2606 OID 17188)
-- Name: artist pk_artist; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist
    ADD CONSTRAINT pk_artist PRIMARY KEY (id);


--
-- TOC entry 3314 (class 2606 OID 17416)
-- Name: artist_followers pk_artist_followers; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist_followers
    ADD CONSTRAINT pk_artist_followers PRIMARY KEY (artist_id, follower_id);


--
-- TOC entry 3298 (class 2606 OID 17286)
-- Name: episode pk_episode; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.episode
    ADD CONSTRAINT pk_episode PRIMARY KEY (id);


--
-- TOC entry 3300 (class 2606 OID 17295)
-- Name: episode_category pk_episode_category; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.episode_category
    ADD CONSTRAINT pk_episode_category PRIMARY KEY (id);


--
-- TOC entry 3316 (class 2606 OID 17431)
-- Name: follows pk_follows; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.follows
    ADD CONSTRAINT pk_follows PRIMARY KEY (follower_id, followed_id);


--
-- TOC entry 3290 (class 2606 OID 17224)
-- Name: library pk_library; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library
    ADD CONSTRAINT pk_library PRIMARY KEY (id);


--
-- TOC entry 3312 (class 2606 OID 17401)
-- Name: library_playlist pk_library_playlist; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library_playlist
    ADD CONSTRAINT pk_library_playlist PRIMARY KEY (library_id, playlist_id);


--
-- TOC entry 3288 (class 2606 OID 17212)
-- Name: listener pk_listener; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.listener
    ADD CONSTRAINT pk_listener PRIMARY KEY (id);


--
-- TOC entry 3310 (class 2606 OID 17391)
-- Name: playlist pk_playlist; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.playlist
    ADD CONSTRAINT pk_playlist PRIMARY KEY (id);


--
-- TOC entry 3318 (class 2606 OID 17462)
-- Name: playlist_song pk_playlist_song; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.playlist_song
    ADD CONSTRAINT pk_playlist_song PRIMARY KEY (playlist_id, song_id);


--
-- TOC entry 3294 (class 2606 OID 17239)
-- Name: podcast pk_podcast; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.podcast
    ADD CONSTRAINT pk_podcast PRIMARY KEY (id);


--
-- TOC entry 3302 (class 2606 OID 17300)
-- Name: podcast_episode pk_podcast_episode; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.podcast_episode
    ADD CONSTRAINT pk_podcast_episode PRIMARY KEY (podcast_id, episode_id);


--
-- TOC entry 3280 (class 2606 OID 17175)
-- Name: profile pk_profile; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.profile
    ADD CONSTRAINT pk_profile PRIMARY KEY (id);


--
-- TOC entry 3304 (class 2606 OID 17317)
-- Name: song pk_song; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.song
    ADD CONSTRAINT pk_song PRIMARY KEY (id);


--
-- TOC entry 3306 (class 2606 OID 17345)
-- Name: song_category pk_song_category; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.song_category
    ADD CONSTRAINT pk_song_category PRIMARY KEY (id);


--
-- TOC entry 3286 (class 2606 OID 17214)
-- Name: artist uk_artist_name; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist
    ADD CONSTRAINT uk_artist_name UNIQUE (name);


--
-- TOC entry 3292 (class 2606 OID 17479)
-- Name: library uk_library; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library
    ADD CONSTRAINT uk_library UNIQUE (listener_id);


--
-- TOC entry 3282 (class 2606 OID 17177)
-- Name: profile uk_profile_username; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.profile
    ADD CONSTRAINT uk_profile_username UNIQUE (username);


--
-- TOC entry 3336 (class 2620 OID 17494)
-- Name: listener add_library; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER add_library AFTER INSERT ON public.listener FOR EACH ROW EXECUTE FUNCTION public.add_library_func();


--
-- TOC entry 3338 (class 2620 OID 17522)
-- Name: playlist_song decrease_song_amount; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER decrease_song_amount AFTER DELETE ON public.playlist_song FOR EACH ROW EXECUTE FUNCTION public.decrease_song_amount_func();


--
-- TOC entry 3337 (class 2620 OID 17524)
-- Name: library_playlist increase_playlist_amount; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER increase_playlist_amount AFTER INSERT ON public.library_playlist FOR EACH ROW EXECUTE FUNCTION public.increase_playlist_amount_func();


--
-- TOC entry 3339 (class 2620 OID 17520)
-- Name: playlist_song increase_song_amount; Type: TRIGGER; Schema: public; Owner: postgres
--

CREATE TRIGGER increase_song_amount AFTER INSERT ON public.playlist_song FOR EACH ROW EXECUTE FUNCTION public.increase_song_amount_func();


--
-- TOC entry 3321 (class 2606 OID 17257)
-- Name: album fk_album_artist; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.album
    ADD CONSTRAINT fk_album_artist FOREIGN KEY (artist) REFERENCES public.artist(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 3325 (class 2606 OID 17356)
-- Name: album_song fk_album_song_album; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.album_song
    ADD CONSTRAINT fk_album_song_album FOREIGN KEY (album_id) REFERENCES public.album(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3326 (class 2606 OID 17361)
-- Name: album_song fk_album_song_song; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.album_song
    ADD CONSTRAINT fk_album_song_song FOREIGN KEY (song_id) REFERENCES public.song(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3330 (class 2606 OID 17417)
-- Name: artist_followers fk_artist_followers_artist; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist_followers
    ADD CONSTRAINT fk_artist_followers_artist FOREIGN KEY (artist_id) REFERENCES public.artist(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3331 (class 2606 OID 17422)
-- Name: artist_followers fk_artist_followers_follower; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.artist_followers
    ADD CONSTRAINT fk_artist_followers_follower FOREIGN KEY (follower_id) REFERENCES public.listener(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3319 (class 2606 OID 17485)
-- Name: library fk_library_listener_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library
    ADD CONSTRAINT fk_library_listener_id FOREIGN KEY (listener_id) REFERENCES public.listener(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 3328 (class 2606 OID 17497)
-- Name: library_playlist fk_library_playlist_library; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library_playlist
    ADD CONSTRAINT fk_library_playlist_library FOREIGN KEY (library_id) REFERENCES public.library(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 3329 (class 2606 OID 17453)
-- Name: library_playlist fk_library_playlist_playlist; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.library_playlist
    ADD CONSTRAINT fk_library_playlist_playlist FOREIGN KEY (playlist_id) REFERENCES public.playlist(id) NOT VALID;


--
-- TOC entry 3327 (class 2606 OID 17392)
-- Name: playlist fk_playlist; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.playlist
    ADD CONSTRAINT fk_playlist FOREIGN KEY (creater) REFERENCES public.listener(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3334 (class 2606 OID 17504)
-- Name: playlist_song fk_playlist_song_playlist_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.playlist_song
    ADD CONSTRAINT fk_playlist_song_playlist_id FOREIGN KEY (playlist_id) REFERENCES public.playlist(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 3335 (class 2606 OID 17509)
-- Name: playlist_song fk_playlist_song_song_id; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.playlist_song
    ADD CONSTRAINT fk_playlist_song_song_id FOREIGN KEY (song_id) REFERENCES public.song(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 3320 (class 2606 OID 17240)
-- Name: podcast fk_podcast_artist; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.podcast
    ADD CONSTRAINT fk_podcast_artist FOREIGN KEY (artist) REFERENCES public.artist(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3322 (class 2606 OID 17306)
-- Name: podcast_episode fk_podcast_episode_episode; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.podcast_episode
    ADD CONSTRAINT fk_podcast_episode_episode FOREIGN KEY (episode_id) REFERENCES public.episode(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3323 (class 2606 OID 17301)
-- Name: podcast_episode fk_podcast_episode_podcast; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.podcast_episode
    ADD CONSTRAINT fk_podcast_episode_podcast FOREIGN KEY (podcast_id) REFERENCES public.podcast(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3324 (class 2606 OID 17346)
-- Name: song fk_song_category; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.song
    ADD CONSTRAINT fk_song_category FOREIGN KEY (category) REFERENCES public.song_category(id) ON UPDATE CASCADE ON DELETE CASCADE NOT VALID;


--
-- TOC entry 3332 (class 2606 OID 17437)
-- Name: follows pk_follows_followed; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.follows
    ADD CONSTRAINT pk_follows_followed FOREIGN KEY (followed_id) REFERENCES public.listener(id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3333 (class 2606 OID 17432)
-- Name: follows pk_follows_follower; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.follows
    ADD CONSTRAINT pk_follows_follower FOREIGN KEY (follower_id) REFERENCES public.listener(id) ON UPDATE CASCADE ON DELETE CASCADE;


-- Completed on 2022-12-26 16:55:42

--
-- PostgreSQL database dump complete
--

